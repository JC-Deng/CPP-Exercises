#include <iostream>
#include "q228def.h"

int main(int argc, char const *argv[])
{
    int (*p)(int) = factorial;
    int a = 5;
    int res = factorial(5);

    std::cout << factorial(5) << std::endl;
    std::cout << p(5) << std::endl;

    return 0;
}
