#include <iostream>
#include <complex>

class Multiply
{
    public:
        double operator()(double a, double b)
        {
            return a*b;
        }
        double operator()(const std::complex<double> &a,
            const std::complex<double> &b)
        {
            return a.real()*b.real() - a.imag()*b.imag();
        }

};

int main()
{
    // Replace the following preprocessor include directive with
    // the defintion of the multiply functor.
    // #include "generic_lambda_1_b.cpp"

    Multiply multiply;
    using namespace std::literals;
    std::cout
    << multiply(2, 3) << " "
    << multiply(0.5, 2.0) << " "
    << multiply(2, 0.25) << " "
    << multiply(1.0 + 1.0i, 1.0 - 1.0i) << "\n";

    return 0;
}
