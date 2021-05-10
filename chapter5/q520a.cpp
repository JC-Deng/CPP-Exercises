#include <iostream>
#include <iomanip>

template <class T>
std::ostream& Output(std::ostream &os, const T &in)
{
    os << in;
    return os;
}

template <class T, class... Ts>
std::ostream& Output(std::ostream &os, const T &in, const Ts&... in_s)
{
    os << in;
    Output(os, in_s...);
    return os;
}

int main(int argc, char const *argv[])
{
    // Output "1\n".
    Output(std::cout, 1, "\n");

    // Output "Hello World!\n".
    Output(std::cout, "Hello ", "World!", "\n");

    // Output "Testing***1***2***3\n"
    Output(std::cout,
    std::setfill('*'),
    "Testing",
    std::setw(4), 1,
    std::setw(4), 2,
    std::setw(4), 3,
    "\n");

    return 0;
}
