#include <iostream>
#include <numeric>
#include <vector>

using ull = unsigned long long;

int main()
{
    std::string line;
    std::getline(std::cin, line);

    std::vector<ull> beam(line.size(), 0);
    for (uint i = 0; i < line.size(); i++) {
        if (line[i] == 'S')
            beam[i] = 1;
    }

    while (std::getline(std::cin, line)) {
        std::vector<ull> next_beam = beam;
        for (uint i = 0; i < line.size(); i++) {
            if (line[i] == '^' && beam[i]) {
                if (i < line.size() - 1)
                    next_beam[i+1] += next_beam[i];
                if (i > 0)
                    next_beam[i-1] += next_beam[i];
                next_beam[i] = 0;
            }
        }
        beam = next_beam;
    }
    std::cout << std::accumulate(beam.begin(), beam.end(), 0ULL) << '\n';
    return 0;
}