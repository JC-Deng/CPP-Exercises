#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    auto prefix_increment = [](auto &x){
        return ++x;
    };
    int a = 5;
    double b = 6;
    std::cout << prefix_increment(a) << '\n'
        << prefix_increment(b) << '\n';
    return 0;
}
