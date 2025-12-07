#include <iostream>
#include <string>


int main()
{
    std::string s;
    int pos = 50;
    int cnt = 0;
    while (std::cin >> s) {
        char dir = s[0];
        int amount = stoi(s.substr(1));

        if (dir == 'L')
            pos = (pos - amount + 100) % 100;
        else
            pos = (pos + amount) % 100;

        if (pos == 0)
            cnt++;
    }
    std::cout << cnt;
    
    return 0;
}