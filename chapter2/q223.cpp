#include <iostream>

int StrToInt(const char *c_style_string)
{
    int res = 0, flag;

    if (*c_style_string == '+')
    {
        flag = 1;
    }
    else if (*c_style_string == '-')
    {
        flag = -1;
    }
    else
    {
        return 0;
    }

    c_style_string++;
    while (*c_style_string != '\0')
    {
        res = 10*res + (int)*c_style_string - 48;
        c_style_string++;
    }

    return flag*res;
}

int main(int argc, char const *argv[])
{
    const char a[] = "-122227";
    const char b[] = "+2151";
    const char s[] = "123";

    std::cout << StrToInt(a) << '\n'
        << StrToInt(b) << '\n'
        << StrToInt(s) << std::endl;

    return 0;
}
