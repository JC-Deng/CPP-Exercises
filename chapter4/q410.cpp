#include<iostream>

template <int N>
constexpr int factorial()
{
    long long i = 1, sum = 1;
    while (i <= N) {
        sum *= i;
        ++i;
    }
    return sum;
}

template <>
constexpr int factorial<0>()
{
    return 1;
}

int main(int argc, char const *argv[])
{
    std::cout << factorial<0>() << '\n'
        << factorial<3>() << '\n'
        << factorial<5>() << '\n'
        << factorial<7>() << '\n';

    return 0;
}
