#include <iostream>
#include <numeric>
#include <string>
#include <sstream>
#include <vector>

using ull = unsigned long long;

int main()
{
    std::vector<std::string> lines;
    for (std::string line; std::getline(std::cin, line);)
        lines.push_back(line);

    std::vector<std::string> ops;
    std::istringstream ops_line(lines.back());
    for (std::string op; ops_line >> op;)
        ops.push_back(op);
    lines.pop_back();

    const auto ncols = ops.size();
    std::vector<ull> res(ncols, 0);
    for (uint i = 0; i < ncols; i++) {
        if (ops[i] == "*")
            res[i] = 1;
    }

    for (auto& row : lines) {
        std::istringstream iss(row);
        ull n;
        for (uint i = 0; i < ncols; i++) {
            iss >> n;
            if (ops[i] == "*")
                res[i] *= n;
            else
                res[i] += n;
        }
    }

    std::cout << std::accumulate(res.begin(), res.end(), 0ULL) << '\n';
}