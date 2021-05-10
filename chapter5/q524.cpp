#include <iostream>
#include <algorithm>
#include <vector>

bool IsSorted(const std::vector<double> &v, int &num_compares)
{
    double temp = *v.begin();
    int break_res = 0;
    auto iter = std::find_if(v.begin(), v.end(),
        [&](double x) -> bool
        {
            break_res = x < temp;
            temp = x;
            num_compares++;
            return break_res;
        });
    return iter == v.end();
}

int main(int argc, char const *argv[])
{
    std::vector<double> test_true{1, 2, 3, 4, 5};
    std::vector<double> test_false{1, 5, 2, 3, 4};
    int num_compare = 0;
    std::cout << IsSorted(test_true, num_compare) << '\n'
        << num_compare << '\n';
    num_compare = 0;
    std::cout << IsSorted(test_false, num_compare) << '\n'
        << num_compare << '\n';
    return 0;
}
