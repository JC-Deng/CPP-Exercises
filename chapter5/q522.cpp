#include <iostream>
#include <vector>
#include <algorithm>

int FindFirstNegative(const std::vector<int> &vec)
{
    auto res = std::find_if(vec.begin(), vec.end(),
        [](const int &x){return x < 0;});
    if (res == vec.end()) {
        return -1;
    } else {
        return *res;
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> test_vec_1{1, 3, 5, 7};
    std::vector<int> test_vec_2{1, 3, -5, 7};
    std::cout << FindFirstNegative(test_vec_1) << '\n'
        << FindFirstNegative(test_vec_2) << '\n';
    return 0;
}
