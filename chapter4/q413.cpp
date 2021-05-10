#include <iostream>

template <typename T>
T sum(T t)
{
    return t;
}

template <typename T, typename... Ts>
T sum(T t, Ts... ts)
{
    return t + sum(ts...);
}

int main(int argc, char const *argv[])
{
    std::cout << sum(1.1, 2.1, 3, 4) << '\n';
    return 0;
}
