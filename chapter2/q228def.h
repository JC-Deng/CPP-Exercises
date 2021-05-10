#pragma once

int factorial(int x)
{
    return x;
}

#define factorial(x) ((x) * factorial((x) - 1))