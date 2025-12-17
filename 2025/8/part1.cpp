#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <utility>
#include "unionfind.hpp"

using ll = long long;

struct point {
    ll x, y, z;
};

ll dist_sq(const point& a, const point& b)
{
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    ll dz = a.z - b.z;
    return dx*dx + dy*dy + dz*dz;
}

void print_point(const point& p)
{
    std::cout << p.x << ',' << p.y << ',' << p.z << '\n';
}

int main()
{
    std::vector<point> points;
    
    for (std::string line; std::getline(std::cin, line);) {
        std::istringstream iss(line);
        point p;
        char comma;
        iss >> p.x >> comma >> p.y >> comma >> p.z;
        points.push_back(p);
    }

    using dist_pair = std::pair<ll, std::pair<point*, point*>>;
    std::priority_queue<dist_pair, std::vector<dist_pair>, std::greater<dist_pair>> min_pairs;
    for (uint i = 0; i < points.size(); i++) {
        for (uint j = i + 1; j < points.size(); j++) {
            auto& a = points[i];
            auto& b = points[j];
            min_pairs.push({dist_sq(a, b), {&a, &b}});
        }
    }

    unionfind<point> circuits(points);
    for (uint i = 0; i < 1000; i++) {
        auto mp = min_pairs.top();
        min_pairs.pop();
        circuits.merge(mp.second.first, mp.second.second);
    }
    
    std::vector<unsigned long long> sizes(circuits.m_size.size());
    for (auto p : circuits.m_size)
        sizes.push_back(p.second);
    std::sort(sizes.rbegin(), sizes.rend());

    std::cout << sizes[0] * sizes[1] * sizes[2] << '\n';
    return 0;
}