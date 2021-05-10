#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<double> in_vec;
    double in_x;
    while (std::cin >> in_x){
        in_vec.push_back(in_x);
    }
    std::for_each(in_vec.begin(), in_vec.end(),
        [](double &x){std::cout << x << ' ';});
    std::cout << '\n';

    std::sort(in_vec.begin(), in_vec.end(),
        [](const double &x, const double &y) -> bool {return y < x;});
    std::for_each(in_vec.begin(), in_vec.end(),
        [](double &x){std::cout << x << ' ';});
    std::cout << '\n';
    return 0;
}
