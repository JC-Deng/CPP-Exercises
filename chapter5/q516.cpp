#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<int> test_vec{1, 3, 5, 7};
    std::vector<int> test_vec_2{1, 3, 5, 8, 9};
    auto lambda = [](int &x) -> bool {return (x&1)!=0;};
    std::cout << std::all_of(test_vec.begin(),
        test_vec.end(), lambda) << '\n'
        << std::all_of(test_vec_2.begin(),
        test_vec_2.end(), lambda) << '\n';
    return 0;
}
