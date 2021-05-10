#include <iostream>

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

template <class... T>
void output(std::ostream &os, const T&... t)
{
    std::cout << "OUTPUT: ";
    Output(os, t...);
}

int main(int argc, char const *argv[])
{
    // Output "OUTPUT: 1 2 3\n".
    output(std::cout, 1, " ", 2, " ", 3, "\n");

    // Output "OUTPUT: "Hello World!\n".
    output(std::cout, 'H', "ello", ' ', 'W', "orld", '!', '\n');
    return 0;
}
