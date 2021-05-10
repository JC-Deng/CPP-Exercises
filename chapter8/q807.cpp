#include <iostream>
#include <utility>
#include <typeinfo>

template <class T>
void func2(T p) {}

template <class T>
void func(T &&p)
{
  func2(std::forward<T>(p));
}

int main()
{
  const double cd = 42.42;
  double d = cd;
  func(d); // Passing reference of d. T is deduced to double &.
  func(cd); // Passing referenc of cd. T is deduced to const double &.
  func(d + d); // Passing the rvalue reference of temperate object. T is deduced to double &&.
  func(std::move(d)); // Passing the rvalue reference of d. T is deduced to double &&.
}
