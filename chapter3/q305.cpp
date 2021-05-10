// This is not a good way to use operator overloading.
// The apparent operator ** is just a combination
// of dereference operator * and multiply operator *.
// This can allow some weired pieces of code like
// x *** y, which will have the same effect of x ** y.
// Modifying operator in a way which is totally
// unrelated to its original meaning should not be a
// preferable approach.
#include <iostream>
#include <cmath>

class Exponent
{
    private:
        double e;
    
    public:
        int a;
        Exponent(double);
        friend const Exponent& operator*(const Exponent&);
        friend double operator*(double, const Exponent&);
};

Exponent::Exponent(double e_in) : e(e_in) {}

const Exponent& operator*(const Exponent &e_obj)
{
    return e_obj;
}

double operator*(double x, const Exponent &e_obj)
{
    return std::pow(x, e_obj.e);
}

int main(int argc, char const *argv[])
{
    const double x = 2.0;
    const Exponent y = 4.0;
    const Exponent *pt = &y;
    
    std::cout << x ** y << "\n";
    return 0;
}
