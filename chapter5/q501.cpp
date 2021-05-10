#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <string>

template <template <class U, class... Ts> class T,
    template <class U, class... Ts> class T2,
    template <class U, class... Ts> class T3, class U>
T3<U>& merge(const T<U> &opn1, const T2<U> &opn2, T3<U> &opn3)
{
    typename T<U>::const_iterator i;
    for (i = opn1.begin(); i != opn1.end(); i++) {
        opn3.push_back(*i);
    }
    typename T2<U>::const_iterator j;
    for (j = opn2.begin(); j != opn2.end(); j++) {
        opn3.push_back(*j);
    }
    return opn3;
}

template <template <class U, class... Ts> class T,
    template <class U, class... Ts> class T2, class U>
std::set<U>& merge(const T<U> &opn1, const T2<U> &opn2, std::set<U> &opn3)
{
    typename T<U>::const_iterator i;
    for (i = opn1.begin(); i != opn1.end(); i++) {
        opn3.insert(*i);
    }
    typename T2<U>::const_iterator j;
    for (j = opn2.begin(); j != opn2.end(); j++) {
        opn3.insert(*j);
    }
    return opn3;
}

template <class T, template <class U, class... Ts> class T2, class U>
T& output(T &os, T2<U> &opn)
{
    typename T2<U>::const_iterator i;
    for (i = opn.begin(); i != opn.end(); i++) {
        os << *i << ' ';
    }
    return os;
}

int main(int argc, char *argv[])
{
    const std::vector<std::string> c1{"delta", "beta", "alpha"};
    const std::list<std::string> c2{"delta", "beta", "alpha"};
    const std::set<std::string> c3{"one", "two", "four"};
    std::vector<std::string> d1;
    std::list<std::string> d2;
    std::set<std::string> d3;
    merge(c1, c2, d1);
    output(std::cout, d1) << "\n";
    merge(c2, c3, d2);
    output(std::cout, d2) << "\n";
    merge(c3, c1, d3);
    output(std::cout, d3) << "\n";
    return 0;
}