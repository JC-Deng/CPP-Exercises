#include <iostream>
#include <limits>

int main(int argc, char const *argv[])
{
    std::cout << "The lowest value of char is: "
    << std::numeric_limits<char>::lowest() << '\n'
    << "The smallest value of char is: "
    << std::numeric_limits<char>::min() << '\n'
    << "The largest value of char is: "
    << std::numeric_limits<char>::max() << '\n' << std::endl;

    std::cout << "The lowest value of short is: "
    << std::numeric_limits<short>::lowest() << '\n'
    << "The smallest value of short is: "
    << std::numeric_limits<short>::min() << '\n'
    << "The largest value of short is: "
    << std::numeric_limits<short>::max() << '\n' << std::endl;

    std::cout << "The lowest value of int is: "
    << std::numeric_limits<int>::lowest() << '\n'
    << "The smallest value of int is: "
    << std::numeric_limits<int>::min() << '\n'
    << "The largest value of int is: "
    << std::numeric_limits<int>::max() << '\n' << std::endl;

    std::cout << "The lowest value of long is: "
    << std::numeric_limits<long>::lowest() << '\n'
    << "The smallest value of long is: "
    << std::numeric_limits<long>::min() << '\n'
    << "The largest value of long is: "
    << std::numeric_limits<long>::max() << '\n' << std::endl;

    std::cout << "The lowest value of long long is: "
    << std::numeric_limits<long long>::lowest() << '\n'
    << "The smallest value of long long is: "
    << std::numeric_limits<long long>::min() << '\n'
    << "The largest value of long long is: "
    << std::numeric_limits<long long>::max() << '\n' << std::endl;

    std::cout << "The lowest value of float is: "
    << std::numeric_limits<float>::lowest() << '\n'
    << "The smallest value of float is: "
    << std::numeric_limits<float>::min() << '\n'
    << "The largest value of float is: "
    << std::numeric_limits<float>::max() << '\n' << std::endl;

    std::cout << "The lowest value of double is: "
    << std::numeric_limits<double>::lowest() << '\n'
    << "The smallest value of double is: "
    << std::numeric_limits<double>::min() << '\n'
    << "The largest value of double is: "
    << std::numeric_limits<double>::max() << '\n' << std::endl;

    std::cout << "The lowest value of long double is: "
    << std::numeric_limits<long double>::lowest() << '\n'
    << "The smallest value of long double is: "
    << std::numeric_limits<long double>::min() << '\n'
    << "The largest value of long double is: "
    << std::numeric_limits<long double>::max() << '\n' << std::endl;

    std::cout << "The lowest value of unsigned int is: "
    << std::numeric_limits<unsigned int>::lowest() << '\n'
    << "The smallest value of unsigned int is: "
    << std::numeric_limits<unsigned int>::min() << '\n'
    << "The largest value of unsigned int is: "
    << std::numeric_limits<unsigned int>::max() << '\n' << std::endl;

    return 0;
}
