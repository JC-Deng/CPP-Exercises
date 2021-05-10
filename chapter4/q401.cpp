#include <iostream>

template <class T> T min3(T a, T b, T c)
{
    T min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    return min;
}

int main(int argc, char const *argv[])
{
    std::cout << min3<int>(1, 2, 3) << '\n'
        << min3<double>(1.4, 1.2, 1.7) << '\n';
    return 0;
}
