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

    while (std::getline(std::cin, line)) {
        if (line.size() == 0)
            break;
        
        std::istringstream iss(line);
        ull start, end;
        char dash;
        iss >> start >> dash >> end;
        intervals.push_back({start, end});
    }

    std::sort(intervals.begin(), intervals.end());
    for (unsigned i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= intervals[i-1].second) {
            intervals[i-1].second = std::max(intervals[i-1].second, intervals[i].second);
            intervals.erase(intervals.begin() + i--);
        }
    }

    ull count = 0;
    for (auto& interval : intervals)
        count += interval.second - interval.first + 1;
    std::cout << "Count: " << count << '\n';
    return 0;
}