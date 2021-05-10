#include <iostream>
#include <complex>

typedef std::complex<double> Complex;

const Complex getConst()
{
  return Complex(1.0, 2.0);
}

void func1(const Complex& a)
{
  std::cout << "func1(const Complex&) called\n";
}

void func1(Complex& a)
{
  std::cout << "func1(Complex&) called\n";
}

void func1(Complex&& a)
{
  std::cout << "func1(Complex&&) called\n";
}

void func2(const Complex& a)
{
  std::cout << "func2(const Complex&) called\n";
}

void func2(const Complex&& a)
{
  std::cout << "func2(const Complex&&) called\n";
}

int main()
{
  const Complex j{0.0, 1.0};
  Complex a{1.0, 1.0};
  const Complex* p = &j;

  func1(a); // func1(Complex&) called.
  func1(j); // func1(const Complex&) called.
  func1(a * a); // func1(Complex&&) called.
  func1(getConst()); // func2(const Complex&). It has higher priority.
  func1(*p); // func1(const Complex&) called.

  func2(a + a); // func2(const Complex&&) called. operator+() returned constexpr Complex.
  func2(j); // func2(const Complex&) called. j is const rvalue.
  func2(getConst()); // func2(const Complex&&) called. Best match.  
}
