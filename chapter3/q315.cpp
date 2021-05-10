#include <iostream>

auto make_functor(int x)
{
    static int a = 0;
    return [=](int y) {
        static int b = 0;
        return y + x + (a++) + (b++);
    };
}

int main()
{
    auto f1 = make_functor(1);
    auto f2 = make_functor(2);
    std::cout << f1(0) << '\n';
    std::cout << f2(0) << '\n';
    std::cout << f1(1) << '\n';
    std::cout << f2(1) << '\n';
}