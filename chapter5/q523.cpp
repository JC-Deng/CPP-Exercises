#include <iostream>
#include <vector>
#include <algorithm>

void QuadraticTransform(std::vector<int> &opn,
    std::vector<int> &res, int a, int b, int c)
{
    std::transform(opn.begin(), opn.end(), std::back_inserter(res),
        [=](int x){return a*x*x + b*x + c;});
}

int main(int argc, char const *argv[])
{
    std::vector<int> test_vec{1, 2, 3, 4};
    std::vector<int> res;
    QuadraticTransform(test_vec, res, 2, 1, 1);
    for (auto num : res) {
        std::cout << num << '\n';
    }
    return 0;
}
