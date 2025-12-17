#pragma once

#include <cstddef>
#include <vector>
#include <unordered_map>

template <typename T>
struct unionfind {
    unionfind(std::vector<T>& v)
    {
        m_parent.reserve(v.size());
        m_size.reserve(v.size());
        for (auto& x : v) {
            m_parent[&x] = &x;
            m_size[&x] = 1;
        }
    }

    T* find(T* x)
    {
        while (m_parent[x] != x)
            x = m_parent[x];
        return x;
    }

    T* merge(T* a, T* b)
    {
        auto pa = find(a);
        auto pb = find(b);

        if (pa == pb)
            return pa;

        if (m_size[pa] < m_size[pb])
            std::swap(pa, pb);

        m_size[pa] += m_size[pb];
        m_parent[pb] = pa;
        return pa;
    }

    std::unordered_map<T*, T*> m_parent;
    std::unordered_map<T*, size_t> m_size;
};