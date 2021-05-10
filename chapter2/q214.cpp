#include <iostream>

int StrLen(const char *c_style_string)
{
    int res = 0;

    while (*c_style_string)
    {
        res++;
        c_style_string++;
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    const char *test_pointer = "The test string.\0asdfasdf";
    std::cout << StrLen(test_pointer) << std::endl;
    
    return 0;
}
