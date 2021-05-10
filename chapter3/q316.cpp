#include <iostream>
auto f = [](auto x)
{
    static int c = 0;
    return (++c) + x;
};

int main()
{
    std::cout << f(1) << '\n';
    std::cout << f(0.5) << '\n';
    std::cout << f(1) << '\n';
    std::cout << f(0.5) << '\n';
}