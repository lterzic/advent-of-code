#include <iostream>
#include <string>

static uint64_t count_digits(uint64_t n)
{
    uint64_t count = 0;
    while (n) {
        count++;
        n /= 10UL;
    }
    return count;
}

static uint64_t pow10(uint64_t p)
{
    uint64_t n = 1UL;
    while (p--)
        n *= 10;
    return n;
}

static uint64_t next_invalid(uint64_t n)
{
    uint64_t digits = count_digits(n);

    if (digits % 2) {
        return pow10(digits) + pow10((digits - 1UL) / 2);
    } else {
        auto half_mask = pow10(digits / 2);
        auto left = n / half_mask;
        auto right = n % half_mask;
        if (left < right)
            left++;
        return left * half_mask + left;
    }
}

static void sum_repeated_in_range(uint64_t start, uint64_t end, uint64_t& sum)
{
    for (uint64_t i = next_invalid(start); i <= end; i = next_invalid(++i)) {
        sum += i;
    }
}

int main()
{
    std::string s;
    uint64_t sum = 0;
    while (std::getline(std::cin, s, ',')) {
        auto split_idx = s.find('-');
        uint64_t start = std::stoull(s.substr(0, split_idx));
        uint64_t end = std::stoull(s.substr(split_idx + 1));
        sum_repeated_in_range(start, end, sum);
    }
    std::cout << sum << std::endl;
    return 0;
}