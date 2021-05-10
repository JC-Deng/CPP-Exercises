#include<iostream>

int x = 1;

auto f1 = [] () {return x + 1;};
auto f2 = [x = x] () {return x + 1;};

int main(int argc, char const *argv[])
{
    x = 10;
    std::cout << f1() << " " << f2() << '\n';
    return 0;
}
