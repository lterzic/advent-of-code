#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

static uint64_t turn_on_machine(std::string& line)
{
    uint64_t lights = 0;
    std::vector<uint64_t> buttons;

    std::string light_str = line.substr(1, line.find(']') - 1);
    for (uint i = 0; i < light_str.size(); i++)
        if (light_str[i] == '#')
            lights |= 1ULL << i;

    size_t numpos = 0;
    while ((numpos = line.find('(', numpos + 1)) != std::string::npos) {
        std::string num_str = line.substr(numpos, line.find(')', numpos) - numpos);
        std::istringstream iss(num_str);

        uint64_t button = 0;
        char temp;
        for (uint64_t p; iss >> temp >> p;) {
            button |= 1ULL << p;
        }
        buttons.push_back(button);
    }

    uint64_t min_count = UINT64_MAX;
    for (uint64_t comb = 1; comb < (1ULL << buttons.size()); comb++) {
        uint64_t result = 0, count = 0;
        for (uint64_t i = 0; i < buttons.size(); i++) {
            if (comb & (1ULL << i)) {
                result ^= buttons[i];
                count++;
            }
        }
        if (result == lights)
            min_count = std::min(min_count, count);
    }
    return min_count;
}

int main()
{
    uint64_t total = 0;
    for (std::string line; std::getline(std::cin, line);) {
        total += turn_on_machine(line);
    }
    std::cout << total << '\n';
    return 0;
}