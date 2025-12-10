#include <iostream>
#include <sstream>
#include <vector>

static unsigned count_and_remove(std::istream& istream, std::ostringstream& oss)
{
    std::vector<int> curr, prev;
    std::string line, prevline;
    
    unsigned count = 0;    
    while (istream >> line) {
        curr = std::vector<int>(line.size(), 0);
        if (prev.empty()) {
            prev = std::vector<int>(line.size(), 0);
            prevline = std::string(line.size(), '.');
        }

        for (unsigned i = 0; i < line.size(); i++) {
            if (line[i] == '@') {
                if (i > 0) {
                    prev[i-1]++;
                    curr[i-1]++;
                }
                if (i < line.size()-1) {
                    prev[i+1]++;
                    curr[i+1]++;
                }
                prev[i]++;
            }
            if (prevline[i] == '@') {
                if (i > 0)
                    curr[i-1]++;
                if (i < line.size()-1)
                    curr[i+1]++;
                curr[i]++;
            }
        }
        for (unsigned i = 0; i < line.size(); i++) {
            if (prevline[i] == '@' && prev[i] < 4) {
                count++;
                prevline[i] = '.';
            }
        }
        oss << prevline << '\n';
        prev = curr;
        prevline = line;
    }
    for (unsigned i = 0; i < line.size(); i++) {
        if (prevline[i] == '@' && prev[i] < 4) {
            count++;
            prevline[i] = '.';
        }
    }
    oss << prevline << '\n';
    return count;
}

int main()
{
    std::string grid;
    std::ostringstream oss;

    for (std::string s; std::cin >> s;) {
        oss << s << '\n';
    }
    grid = oss.str();

    unsigned count = 0, iter_count = 1;
    while (iter_count > 0) {
        std::istringstream iss(grid);
        oss = std::ostringstream();
        iter_count = count_and_remove(iss, oss);
        grid = oss.str();
        count += iter_count;
    }
    std::cout << "Count: " << count << '\n';
    return 0;
}