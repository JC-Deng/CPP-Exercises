#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>

int main(int argc, char const *argv[])
{
    // (a)
    std::vector<double> rand_vec(100);
    std::for_each(rand_vec.begin(), rand_vec.end(),
        [](double &x){x = drand48();});
    std::for_each(rand_vec.begin(), rand_vec.end(),
        [](const double &x){std::cout << x << '\n';});

    // (b)
    std::vector<int> int_vec{1, 3, 8, 6, 4, 5, 7, 2, 0, 9};
    std::sort(int_vec.begin(), int_vec.end(),
        [](int &a, int &b) -> bool {return a < b;});
    std::for_each(int_vec.begin(), int_vec.end(),
        [](const double &x){std::cout << x << ' ';});
    std::cout << '\n';
    
    // (c)
    std::vector<int> int_vec_2{1, 3, 8, 6, 4, 5, 7, 2, 0, 9};
    std::set<int> infinities{3, 2};
    std::sort(int_vec_2.begin(), int_vec_2.end(),
        [&infinities](int &a, int &b) -> bool
        {
            bool has_a = (infinities.find(a) != infinities.end());
            bool has_b = (infinities.find(b) != infinities.end());
            if (has_a && has_b || !has_a && !has_b) {
                return a < b;
            } else if (has_a) {
                return 0;
            } else {
                return 1;
            }
        }
    );
    std::for_each(int_vec_2.begin(), int_vec_2.end(),
        [](int &x){std::cout << x << ' ';});
    std::cout << '\n';
    return 0;
}
