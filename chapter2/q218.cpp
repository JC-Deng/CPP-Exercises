/* A C-style string will end up with a \0.
Thus it will occupy n+1 size of char. But
strlen will ignore the \0 and return the
apparent length of the string. */
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
    char s[] = "Hello";

    std::cout << sizeof(s) << std::endl;
    std::cout << strlen(s) << std::endl;

    return 0;
}
