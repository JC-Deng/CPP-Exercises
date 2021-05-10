/* I think passing pointers is a preferable
method because the disastrous modification
that's done to the variable is more obvious
this way. If I want to modify the original
object, I have to pass argument in the format
of &a, and write *a in my functions. */

#include <iostream>

void SwapPointers(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void SwapReferences(int &a, int &b)
{
    int temp = a;

    a = b;
    b = temp;
}

int main(int argc, char const *argv[])
{
    int test_a = 3, test_b = 5;
    int test_a_2 = 7, test_b_2 = 9;

    SwapPointers(&test_a, &test_b);
    SwapReferences(test_a_2, test_b_2);

    return 0;
}
