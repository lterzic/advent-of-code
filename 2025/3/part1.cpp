#include <iostream>

using ull = unsigned long long;

int main()
{
    ull sum = 0;

    std::string s;
    while (std::cin >> s) {
        ull max1 = 0, max2 = 0;
        
        for (ull i = 0; i < s.size(); i++) {
            ull jolt = s[i] - '0';
            if (i < s.size() - 1 && jolt > max1) {
                max1 = jolt;
                max2 = 0;
            } else if (jolt > max2) {
                max2 = jolt;
            }
        }
        sum += 10 * max1 + max2;
    }
    
    std::cout << sum << std::endl;
    return 0;
}