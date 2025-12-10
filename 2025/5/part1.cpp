#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using ull = unsigned long long;

int main()
{
    std::vector<std::pair<ull, ull>> intervals;
    std::string line;

    bool interval_input = true;
    while (std::getline(std::cin, line)) {
        if (interval_input && line.size() == 0) {
            interval_input = false;

            std::sort(intervals.begin(), intervals.end());
            for (unsigned i = 1; i < intervals.size(); i++) {
                if (intervals[i].first <= intervals[i-1].second) {
                    intervals[i-1].second = std::max(intervals[i-1].second, intervals[i].second);
                    intervals.erase(intervals.begin() + i--);
                }
            }
            break;
        }
        
        std::istringstream iss(line);
        ull start, end;
        char dash;
        iss >> start >> dash >> end;
        intervals.push_back({start, end});
    }

    ull ing_id;
    unsigned count = 0;

    while (std::cin >> ing_id) {
        auto search_pair = std::make_pair(ing_id, std::numeric_limits<ull>::max());
        auto it = std::upper_bound(intervals.begin(), intervals.end(), search_pair);
        if (it-- == intervals.begin())
            continue;
        if (ing_id >= it->first && ing_id <= it->second)
            count++;
    }
    std::cout << "Count: " << count << '\n';
    return 0;
}