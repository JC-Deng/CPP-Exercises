#include <iostream>

template <typename T>
T minimum(T v)
{
    return v;
}

template <typename T, typename... Args>
T minimum(T first, Args... rest)
{
    return first < minimum(rest...) ? first : minimum(rest...);
}

int main(int argc, char const *argv[])
{
    std::cout << minimum(6, 5, 4, 3, 2, 8, -1, 4, 7) << '\n'
        << minimum(1.1, 2.0, 3.0, 4.0, 5.0, 6.0) << '\n';
    return 0;
}
