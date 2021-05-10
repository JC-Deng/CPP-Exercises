#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>

int main(int argc, char const *argv[])
{
    std::string test_std("19852");
    const char *test_cstyle = "41230";
    int int_std = boost::lexical_cast<int>(test_std);
    int int_cstyle = boost::lexical_cast<int>(test_cstyle);
    std::cout << int_std << '\n'
        << int_cstyle << '\n';
    return 0;
}
