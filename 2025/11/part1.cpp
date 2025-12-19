#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

struct node_s {
    std::vector<node_s*> out;
};

static uint dfs(node_s& curr, node_s& target)
{
    if (&curr == &target)
        return 1;
    
    uint paths_to_target = 0;
    for (auto out_node : curr.out) {
        paths_to_target += dfs(*out_node, target);
    }
    return paths_to_target;
}

int main()
{
    std::unordered_map<std::string, node_s> nodes;

    for (std::string line; std::getline(std::cin, line);) {
        std::istringstream iss(line);
        std::string name;
        iss >> name;
        name.pop_back();
        
        node_s& node = nodes[name];
        while (iss >> name) {
            node.out.push_back(&nodes[name]);
        }
    }

    node_s& you = nodes["you"];
    node_s& out = nodes["out"];
    std::cout << dfs(you, out) << '\n';

    return 0;
}