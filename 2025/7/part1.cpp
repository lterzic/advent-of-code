#include <iostream>
#include <vector>

int main()
{
    std::string line;
    std::getline(std::cin, line);

    std::vector<bool> beam(line.size(), false);
    for (uint i = 0; i < line.size(); i++) {
        if (line[i] == 'S')
            beam[i] = true;
    }

    uint count = 0;
    while (std::getline(std::cin, line)) {
        // Updating a copy instead of directly in case of side by side splitters
        std::vector<bool> next_beam = beam;
        for (uint i = 0; i < line.size(); i++) {
            if (line[i] == '^' && beam[i]) {
                next_beam[i] = false;
                if (i < line.size() - 1)
                    next_beam[i+1] = true;
                if (i > 0)
                    next_beam[i-1] = true;
                count++;
            }
        }
        beam = next_beam;
    }
    std::cout << count << '\n';
    return 0;
}