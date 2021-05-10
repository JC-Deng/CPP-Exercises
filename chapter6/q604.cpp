#include <iostream>
#include <vector>
#include <algorithm>

template <class T, class F>
void StrongSort(std::vector<T> &v, F less)
{
    auto v_temp = v;
    std::sort(v_temp.begin(), v_temp.end(), less);
    // If std::sort throws, v will not be changed.
    v.swap(v_temp);
    // If std::swap throws, v will still be intact.
    // Therefore, StrongSort is now a strong exception
    // safe function.
}

int main(int argc, char const *argv[])
{
    std::vector<double> v{1.1, 1.2, 0.8, 1.15, -2};
    StrongSort(v, [](double a, double b){return a < b;});
    for (auto x : v) {
        std::cout << x << '\n';
    }
    return 0;
}
