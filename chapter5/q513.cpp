#include <iostream>
#include <boost/lexical_cast.hpp>

int itos(const std::string &input)
{
    return boost::lexical_cast<int>(input);
}

int main(int argc, char const *argv[])
{
    std::cout << itos("12345") << '\n';
    return 0;
}
