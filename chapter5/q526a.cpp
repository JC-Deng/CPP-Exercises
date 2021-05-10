#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>

int main(int argc, char const *argv[])
{
    auto print_container =
        [](std::ostream &os, auto &x)
        {
            for (auto elmt : x) {
                os << elmt << ' ';
            }
            os << '\n';
        };
    std::vector<int> test_vec{1, 2, 3};
    std::list<double> test_lst{4, 5, 6};
    std::deque<char> test_deq{'a', 'b', 'c'};
    print_container(std::cout, test_vec);
    print_container(std::cout, test_lst);
    print_container(std::cout, test_deq);
    return 0;
}