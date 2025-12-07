#include <iostream>
#include <string>


int main()
{
    std::string s;
    int pos = 50;
    int cnt = 0;
    while (std::cin >> s) {
        char dir = s[0];
        int amount = std::stoi(s.substr(1));

        if (dir == 'L' && pos > 0)
            pos = 100 - pos;
        
        cnt += (pos + amount) / 100;
        pos = (pos + amount) % 100;

        if (dir == 'L' && pos > 0)
            pos = 100 - pos;        
    }
    std::cout << cnt << "\n";
    
    return 0;
}