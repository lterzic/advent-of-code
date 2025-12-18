#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

using ll = long long;

struct point {
    ll x, y;

    bool operator<(const point& rhs)
    {
        if (x == rhs.x)
            return y < rhs.y;
        return x < rhs.x;
    }
};

ll area(const point& a, const point& b)
{
    ll dx = std::abs(a.x - b.x) + 1;
    ll dy = std::abs(a.y - b.y) + 1;
    return dx * dy;
}

int main()
{
    std::vector<point> points;
    for (std::string line; std::getline(std::cin, line);) {
        std::istringstream iss(line);
        point p;
        char comma;
        iss >> p.x >> comma >> p.y;
        points.push_back(p);
    }
    
    ll max_area = 0;
    for (uint i = 0; i < points.size() - 1; i++) {
        for (uint j = i + 1; j < points.size(); j++) {
            ll a = area(points[i], points[j]);
            max_area = std::max(max_area, a);
        }
    }
    std::cout << max_area << '\n';
    return 0;
}