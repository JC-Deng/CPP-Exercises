#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<std::pair<double, double>>
        test_vec{{5, 1}, {4, 2}, {3, 3}, {2, 4}, {1, 5}};
    std::sort(test_vec.begin(), test_vec.end(),
        [](auto &x1, auto &x2) -> bool
        {
            return x1.first*x1.second <= x2.first*x2.second;
        });
    std::for_each(test_vec.begin(), test_vec.end(),
        [](auto &x)
        {
            std::cout << x.first << ' ' << x.second << '\n';
        });
    return 0;
}
