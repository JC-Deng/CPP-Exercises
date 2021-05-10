#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>

template <class T>
void do_work()
{
    // Replace the following preprocessor include directive with
    // the definitions of print_container and prefix_increment functors.
    auto print_container =
        [](std::ostream &os, auto &x)
        {
            for (auto elmt : x) {
                os << elmt << ' ';
            }
            os << '\n';
        };

    auto prefix_increment = [](auto &x){
        return ++x;
    };
    
    T v{0, 1, 2, 3, 4, 5, 6, 7};
    // Print the elements in the container.
    print_container(std::cout, v);
    // Increment each of the elements in the container.
    std::for_each(v.begin(), v.end(), prefix_increment);
    // Print the elements in the container.
    print_container(std::cout, v);
}

int main()
{
    do_work<std::vector<int>>();
    do_work<std::deque<int>>();
    do_work<std::list<int>>();
}