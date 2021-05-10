#include <iostream>
#include <vector>
#include <algorithm>

std::size_t CountEven(const std::vector<int> &vec)
{
    std::size_t res = 0;
    std::for_each(begin(vec), end(vec),
        [&res](const int &x){res += x&1;});
    // for (auto number : vec) {
    //     res += number&1;
    // }
    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<int> test_vec
        {-2 -1, 0, 1, 2, 3, 4, 5, 7, 9, 11};
    std::cout << CountEven(test_vec) << '\n';
    return 0;
}
