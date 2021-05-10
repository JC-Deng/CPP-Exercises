#include <iostream>

int sqr(int x)
{
    return x * x;
}

int main()
{
    int x = 0;
    int y;
    int z;

    y = ++x; // No temporary object needed. ++ applied directly to int x object.
    x = y++; // A temporary object created to hold the value of y++. Since type of y++ is int but not int&.
    z = x + y; // A temporay object created to hold the value of x + y. The type of x + y is int.
    x = sqr(z) + 42; // A temporary object is created to hold the return value of sqr(z) and the later addition of 42.

    return 0;
}
