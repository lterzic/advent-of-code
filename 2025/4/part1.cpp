#include <iostream>
#include <vector>

int main()
{
    std::vector<int> curr, prev;
    std::string line, prevline;
    
    unsigned count = 0;
    while (std::cin >> line) {
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
            if (prevline[i] == '@' && prev[i] < 4)
                count++;
        }
        prev = curr;
        prevline = line;
    }
    for (unsigned i = 0; i < line.size(); i++) {
        if (prevline[i] == '@' && prev[i] < 4)
            count++;
    }
    std::cout << count << '\n';
    return 0;
}