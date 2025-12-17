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
    while (!min_pairs.empty()) {
        auto mp = min_pairs.top();
        min_pairs.pop();
        
        auto c = circuits.merge(mp.second.first, mp.second.second);
        if (circuits.m_size[c] == points.size()) {
            std::cout << mp.second.first->x * mp.second.second->x << '\n';
            break;
        }
    }
    
    return 0;
}