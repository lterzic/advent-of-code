#include <iostream>

struct aoc_stdin {
    aoc_stdin()
    {
        freopen("input.txt", "r", stdin);
    }
};

aoc_stdin g_stdin;