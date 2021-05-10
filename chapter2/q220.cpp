#include <iostream>

int main(int argc, char const *argv[])
{
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        std::cout << ch << ' '
        << (int)ch << std::endl;
    }
    
    for (char ch = '0'; ch <= '9'; ch++)
    {
        std::cout << ch << ' '
        << (int)ch << std::endl;
    }

    return 0;
}
