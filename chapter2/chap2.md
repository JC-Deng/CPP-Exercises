# Chapter 2

## 2.1
A declaration and a definition: a, c, e, f, i, j.  
Only a declaration: b, d, g, h.

## 2.2
(a) A declaration and an initialization.  
(b) A declaration but not an initialization.  
```C++
int Hello()
{  
    std::cout << "hello, world" << std::endl;  
    return 0;  
}  
int (*p)() = Hello;  
```
(c) A declaration and an initialization.

## 2.3
A declaration and a definition: a, c.  
Only a declaration: b, d.  

## 2.4
```C++
(a) char c = '0';
    char *p = &c;
(b) const char c = '0';
    const char *p = &c;
(c) char c = '0';
    char * const p = &c;
(d) const char c = '0';
    const char * const p = &c;
(e) int TestFunction(double test_arg)
    {
        return 0;
    };
    int (*p)(double) = TestFunction;
(f) int a = 0;
    int *p = &a;
    int **p_2 = &p;
(g) int a[16];
    int (&alias_a)[16] = a;
(h) std::string a[10];
    std::string *p = a;
(i) int a[8];
    int (&alias_a)[8] = a;
```

## 2.5
char, signed char and unsigned char are different types. char may or may not be signed. If char is not signed, then the code is still valid but probably will not behave as expected.

## 2.6
(a) must be true  
(b) must be true  
(c) must be false  
(d) must be true

## 2.7
```C++
(a) typedef char * Type;
(b) typedef const char * Type;
(c) typedef char * const Type;
(d) typedef int (*Type)(float);
(e) typedef long (*Type)[16][8];
(f) typedef int (&Type)[8];
(g) typedef int * (&&Type);
```

## 2.8
```C++
(a) using Type = char *;
(b) using Type = const char *;
(c) using Type = char * const;
(d) using Type = int (*)(float);
(e) using Type = long (*)[16][8];
(f) using Type = int (&)[8];
(g) using Type = int * (&&);
```

## 2.9
```C++
#include "iostream"

int main(int argc, char const *argv[])
{
    std::cout << "Size & alignment" << std::endl;

    std::cout << "int:" << sizeof(int) << " "
    << alignof(int) << std::endl;
    std::cout << "int *:" << sizeof(int*) << " "
    << alignof(int *) << std::endl;

    std::cout << "long:" << sizeof(long) << " "
    << alignof(long) << std::endl;
    std::cout << "long *:" << sizeof(long*) << " "
    << alignof(long *) << std::endl;

    std::cout << "float:" << sizeof(float) << " "
    << alignof(float) << std::endl;
    std::cout << "float *:" << sizeof(float*) << " "
    << alignof(float *) << std::endl;

    std::cout << "double:" << sizeof(double) << " "
    << alignof(double) << std::endl;
    std::cout << "double *:" << sizeof(double*) << " "
    << alignof(double *) << std::endl;    
 
    return 0;
}
```
The output is:
```C++
Size & alignment
int:4 4
int *:4 4
long:4 4
long *:4 4
float:4 4
float *:4 4
double:8 8
double *:4 4
```

## 2.10
a:const int  
b:int  
c:const int  
d:const int &  
e:int  
f:const int *

## 2.11
```C++
int main()
{
    int x = 0;
    int y = 1;
    int& z = x; /* x = 0, y = 1, z = 0 */
    x = y; /* x = 1, y = 1, z = 1 */
    y = z + 1; /* x = 1, y = 2, z = 1 */
    ++z; /* x = 2, y = 2, z = 2 */
}
```

## 2.12
(a) int  
(b) double  
(c) float  
(d) const char *  
(e) unsigned long

## 2.13
```C++
int abs(int);

void func()
{
    int x = 0;
    int y = 0;
    int z;
    ++x;
    // x is an lvalue
    // ++x is an lvalue(lvalueness preserved)   

    y++;
    // y++ is an rvalue(lvalueness is impossible to preserve)
    
    z = x + y;
    // x + y is an rvalue
    // z = x + y is an lvalue
    
    z = abs(x + 1);
    // abs(x + 1) is an rvalue
    x = y;
    // x = y is an lvalue
}
```

## 2.17
0  
Since the increment function is only passing argument by value, no change will be applied to the original object int i.

## 2.19
```C++
(a) a = (((b + (c * d)) >> 1) & 2)  
(b) ((a == 0) && (b != 0)) || (c < 0)  
(c) a & (15 != 15)  
(d) (a++), (b = a)  
(e) (0 <= i) < 8  
(f) a = (b = (c = 0))  
(g) (a[2][1]) *= (f(1, 2) + 1)  
(h) ((a << b) << c) << d  
(i) c = (a < 0)  
(j) (((a++)+b) + a) + (++b)  
(k) a *= (((* b) < 0) ? (- * b) : (* b))
```

## 2.28
(a) #define multiply(x, y) x * y  
```C++
#define multiply(x, y) x * y

int main(int argc, char const *argv[])
{
  int a = 5;
  int b = 4;

  int res = ++multiply(a, b);

  return 0;
}
```
In the above code, since multiply(x, y) is simply a text replacement, operator ++ is applied to a * b before the multiplication happens. a is increased by 1 and the final result is 24. These unwanted behaviours are the downside of macro definitions.


(b) #define maximum(x, y) x > y ? x : y  
```C++
#define maximum(x, y) x > y ? x : y

int main(int argc, char const *argv[])
{
  int a = 5;
  int b = 4;

  int res = ++maximum(a, b);

  return 0;
}
```
Similarly, unwanted behaviour would happen in this code.


(c) #define factorial(x) ((x) * factorial((x) - 1))  
```C++
\\q228.cpp
#include "iostream"
#include "tst2.h"

int normalfunc(int (*)(int))
{
    return 0;
}
int main(int argc, char const *argv[])
{
    int (*p)(int) = factorial;
    int a = 5;
    int res = factorial(5);

    std::cout << factorial(5) << std::endl;
    std::cout << p(5) << std::endl;

    return 0;
}
```
```C++
\\q228.h
#pragma once

int factorial(int x)
{
    return x;
}
#define factorial(x) ((x) * factorial((x) - 1))
```
This macro definition is like modifying the behaviour of a function after its defined, since it can't be wrote or included before the definition of the function, otherwise the definition itself would be replaced. This is a unnatural approach, and user of this exotic file will not be aware that the modification of factorial(x) exists. For example, if the user want to create a pointer to factorial(x), the original factorial(x) will be called, and it behaves differently from the modified factorial(x).

## 2.30
```C++
#include <cmath>

double& get_value(double x)
{
    double result = 0.0;
    for (int i = 0; i < 100; i++)
    {
        result += exp(x + i/100.0);
    }
    return result;
}
```
In this code, the serious problem is that a reference to local variable is returned. If it's not necessary to have an object to store the value, we can simply return value of local variable and write this function as double get_value(double x). If an object is a necessity, one approach is to write double* get_value(double x), use new to allocate memory in the heap and return the address of the result object. However, this approach also has the risk of memory leak. To have a well-rounded solution, we can modify the parameters as void get_value(double x, double *target), and ask for an existing object to hold the value.

## 2.32
Macros expand regardless of any context and compiler participation. This will cause error, and it is very hard to locate. And since namespace is also unable to control the expansion of macros, the following code is erroneous.
```C++
namespace test_namespace_a
{
    void TestFunc (int a, int b, int c) {};
    #define TestFunc(a, b) TestFunc(a, b, 0)
}

namespace test_namespace_b
{
    void TestFunc (int a) {};
    #define TestFunc(a, b) TestFunc(a)
}

int main (int argc, const char *argv[])
{
    test_namespace_a::TestFunc(1, 2);
    test_namespace_b::TestFunc(1, 2);

    return 0;
}
```

## 2.35
For Linux environment(Fedora, Ubuntu), the path of iostream is /usr/include/c++/9/iostream.  
For MinGW in Windows, the path is C:\MinGW\lib\gcc\mingw32\9.2.0\include\c++\iostream.

## 2.36
Internal include guard:  
```C++
// header_foo.h
#ifndef HEADER_FOO_H
#define HEADER_FOO_H
// Contents of header_foo.h
#endif

// header_bar.h
#ifndef HEADER_BAR_H
#define HEADER_BAR_H
#include "header_foo.h"
// Contents of header_bar.h
#endif
```
Theoretically, this approach will guarantee safety, but result in multiple times in reading header_foo.h. However since it's an easy fix in compiler optimization, latest compilers' performance won't be affected by this approach. So this is an orthodox and preferable method.


External include guard:  
```C++
// header_foo.h
#ifndef HEADER_FOO_H
#define HEADER_FOO_H
// Contents of header_foo.h
#endif

// header_bar.h
#ifndef HEADER_FOO_H
#include "header_foo.h"
#endif
// Contents of header_bar.h
```
This method checks the include guard symbol before opening the included file, so it can save compile time. However, no mistake can be introduced in typing the include guard symbol, so extra effort should be paid to avoid error. And the performance boost does not necessarily exist considering the compiler optimization. Therefore, this approach is usually unnecessary.


\#pragma once:
```C++
// header_foo.h
#pragma once
// Contents of header_foo.h

// header_bar.h
#pragma once
#include "header_foo.h"
//contents of header_bar.h
```
This is a method supported by most modern compilers, and usually doesn't cause problems. Error can happen when the same header file is copied to another place and included, but this is considered an error that's easy to fix and doesn't happen often. And it's not in C++ ISO so compilers are not required to support this feature. Since it is very simplistic, I think at least in small projects it's a good approach.
