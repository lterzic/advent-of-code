#include <bits/stdc++.h>

static uint64_t count_digits(uint64_t n)
{
    uint64_t count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

static uint64_t pow10(uint64_t p)
{
    uint64_t n = 1;
    while (p--)
        n *= 10;
    return n;
}

static uint64_t get_layout(uint64_t total_digits, uint64_t pattern_digits)
{
    assert(total_digits % pattern_digits == 0);
    
    uint64_t layout = 1;
    uint64_t layout_cnt = total_digits / pattern_digits - 1;
    while (layout_cnt--) {
        layout = layout * pow10(pattern_digits) + 1;
    };
    return layout;
}

static uint64_t next_multiple(uint64_t start, uint64_t base)
{
    return ((start + base - 1) / base) * base;
}

static void sum_repeated_in_range(uint64_t start, uint64_t end, std::unordered_set<uint64_t>& invalid)
{
    uint64_t dstart = count_digits(start);
    uint64_t dend = count_digits(end);
    
    for (uint64_t dtotal = dstart; dtotal <= dend; dtotal++) {
        for (uint64_t dpattern = 1; dpattern <= dtotal / 2; dpattern++) {
            if (dtotal % dpattern)
                continue;
            
            uint64_t layout = get_layout(dtotal, dpattern);
            for (uint64_t i = next_multiple(start, layout); i <= end; i = next_multiple(++i, layout)) {
                if (count_digits(i / layout) != dpattern)
                    continue;
                invalid.insert(i);
            }
        }
    }
}

int main()
{
    std::string s;
    std::unordered_set<uint64_t> invalid;
    while (std::getline(std::cin, s, ',')) {
        auto split_idx = s.find('-');
        uint64_t start = std::stoull(s.substr(0, split_idx));
        uint64_t end = std::stoull(s.substr(split_idx + 1));
        sum_repeated_in_range(start, end, invalid);
    }
    std::cout << std::accumulate(invalid.begin(), invalid.end(), uint64_t(0)) << std::endl;
    return 0;
}