#include <iostream>
#include <vector>
#include <algorithm>

double median(std::vector<double> &v)
{
    std::size_t n = v.size()/2;
    std::nth_element(v.begin(), v.begin() + n, v.end());
    return v[n];
}

int main(int argc, char const *argv[])
{
    double in;
    std::vector<double> in_vec;
    while (std::cin >> in) {
        in_vec.push_back(in);
    }
    if (!std::cin.eof()) {
        abort();
    }
    std::cout << median(in_vec) << '\n';
    return 0;
}
