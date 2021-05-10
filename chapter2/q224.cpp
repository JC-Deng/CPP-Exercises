/* new is used in StrConcat function but due
to its purpose, it's impossible to pair new[]
and delete[] within the function. In this case,
delete[] is necessary every time when this
function is called, but this is implicit and can be
easily forgot. So memory leak is very possible
when using this function.
*/
#include <iostream>

int CStrLen(const char *a)
{
    int res = 0;
    
    while (*a++ != '\0')
    {
        res++;
    };

    return res;
}

char* StrConcat(const char *sub_a, const char *sub_b)
{ 
    int total_length_a = CStrLen(sub_a),
        total_length_b = CStrLen(sub_b);

    char *p = new char(total_length_a + total_length_b + 1);
    char *p_temp = p;

    // while ((*p_temp++ = *sub_a++) != '\0');
    // --p_temp;
    // while ((*p_temp++ = *sub_b++) != '\0');
    // *p_temp = '\0';

    while (*sub_a != '\0')
    {
        *p_temp = *sub_a;
        p_temp++;
        sub_a++;
    }
    while (*sub_b != '\0')
    {
        *p_temp = *sub_b;
        p_temp++;
        sub_b++;
    }
    *p_temp = '\0';

    return p;
}

int main(int argc, char const *argv[])
{
    char a[] = "test a.";
    char b[] = "test.b";

    char *c = StrConcat(a, b);
    char *c_temp = c;

    while (*c != '\0')
    {
        std::cout << *c;
        c++;
    }
    std::cout << std::endl;

    delete[] c_temp;

    return 0;
}
