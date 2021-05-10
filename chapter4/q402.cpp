#include <iostream>

template <class T> T sum(T* begin, T* end)
{
    typename std::remove_const<T>::type res = 0;
    while (begin != end) {
        res += *begin;
        begin++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    const int i[3] = {1, 2, 3};
    const double d[3] = {1.0, 2.0, 3.0};
    std::cout << sum(&i[0], &i[3]) << "\n";
    std::cout << sum(&d[0], &d[3]) << "\n";
    return 0;
}
