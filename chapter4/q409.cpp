#include <iostream>

template <class T>
class Complex
{
    private:
        T real;
        T imaginary;
    
    public:
        Complex() : real(0), imaginary(0) {}
        Complex(const T &in_real, const T &in_imaginary)
            : real(in_real), imaginary(in_imaginary) {}
        template <class TF> friend Complex<TF> operator+
            (const Complex<TF> &opn1, const Complex<TF> &opn2)
        {
            return Complex(opn1.real + opn2.real,
                opn1.imaginary + opn2.imaginary);
        }
        template <class TF> friend Complex<TF> operator-
            (const Complex<TF> &opn1, const Complex<TF> &opn2)
        {
            return Complex(opn1.real - opn2.real,
                opn1.imaginary - opn2.imaginary);
        }
        template <class TF> friend Complex<TF> operator*
            (const Complex<TF> &opn1, const Complex<TF> &opn2)
        {
            return Complex(opn1.real*opn2.real
                - opn1.imaginary*opn2.imaginary,
                opn1.real*opn2.imaginary
                + opn1.imaginary*opn2.real);
        }
        template <class TF> friend Complex<TF> operator/
            (const Complex<TF> &opn1, const Complex<TF> &opn2)
        {
            if (!opn2.real && !opn2.imaginary) {
                abort();
            }
            return Complex((opn1.real*opn2.real
                + opn1.imaginary*opn2.imaginary)
                /(opn2.real*opn2.real + opn2.imaginary*opn2.imaginary),
                (opn1.imaginary*opn2.real - opn1.real*opn2.imaginary)
                /(opn2.real*opn2.real + opn2.imaginary*opn2.imaginary));
        }
        template <class TF> friend std::ostream& operator<<
            (std::ostream &os, const Complex<TF> &out_obj)
        {
            std::cout << out_obj.real;
            if (out_obj.imaginary >= 0) {
                std::cout << '+' << out_obj.imaginary << 'i';
            } else {
                std::cout << out_obj.imaginary << 'i';
            }
            return os;
        }
};

int main(int argc, char const *argv[])
{
    Complex<double> test_1(1.2, 1.7);
    Complex<double> test_2(1.3, -1.8);

    std::cout << test_1 + test_2 << '\n'
        << test_1 - test_2 << '\n'
        << test_1*test_2 << '\n'
        << test_1/test_2 << '\n';
    return 0;
}
