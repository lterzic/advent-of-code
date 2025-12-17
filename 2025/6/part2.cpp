#include <iostream>
#include <numeric>
#include <string>
#include <sstream>
#include <vector>

using ull = unsigned long long;

int main()
{
    std::vector<std::string> lines;
    for (std::string line; std::getline(std::cin, line);)
        lines.push_back(line);

    std::vector<std::string> ops;
    std::vector<ull> col_widths;
    std::istringstream ops_line(lines.back());
    auto col_start = ops_line.tellg();
    for (std::string op; ops_line >> op;) {
        ops.push_back(op);
        col_widths.push_back(ops_line.tellg() - col_start - 1);
        col_start = ops_line.tellg();
    }
    col_widths.erase(col_widths.begin());
    col_widths.push_back(lines.back().size() - col_start + 1);
    lines.pop_back();

    const auto ncols = ops.size();
    std::vector<std::vector<ull>> col_nums;
    for (auto col_w : col_widths)
        col_nums.push_back(std::vector<ull>(col_w, 0));
    for (auto& row : lines) {
        ull cstart = 0;
        for (uint c = 0; c < ncols; c++) {
            auto num_str = row.substr(cstart, col_widths[c]);
            cstart += col_widths[c] + 1;
            
            for (uint d = 0; d < col_widths[c]; d++) {
                if (num_str[d] != ' ')
                    col_nums[c][d] = col_nums[c][d] * 10 + (num_str[d] - '0');
            }
        }
    }

    std::vector<ull> res(ncols, 0);
    for (uint i = 0; i < ncols; i++) {
        if (ops[i] == "*")
            res[i] = 1;
        for (auto n : col_nums[i])
            if (ops[i] == "*")
                res[i] *= n;
            else
                res[i] += n;
    }

    std::cout << std::accumulate(res.begin(), res.end(), 0ULL) << '\n';
}