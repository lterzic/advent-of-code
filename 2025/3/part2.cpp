#include <iostream>
#include <stack>

using ull = unsigned long long;
constexpr ull TARGET_SIZE = 12;

int main()
{
    ull sum = 0;
    std::string str;
    while (std::cin >> str) {
        std::stack<ull> stack;
        for (ull i = 0; i < str.size(); i++) {
            ull str_left = str.size() - i;
            ull min_stack_size = str_left >= TARGET_SIZE ? 0 : (TARGET_SIZE - str_left);

            ull jolt = str[i] - '0';
            while (!stack.empty() && stack.size() > min_stack_size && stack.top() < jolt)
                stack.pop();
            if (stack.size() < TARGET_SIZE)
                stack.push(jolt);
        }
        ull num[TARGET_SIZE];
        for (ull i = 0; i < TARGET_SIZE; i++) {
            num[TARGET_SIZE - 1 - i] = stack.top();
            stack.pop();
        }
        ull bank = 0;
        for (ull n : num)
            bank = bank * 10 + n;
        sum += bank;
    }
    std::cout << sum << '\n';
    return 0;
}