#include <iostream>
#include <utility>
using std::cout;
using std::endl;
using std::move;
using std::exchange;

class Quadratic
{
    private:
        double a, b, c;
    
    public:
        Quadratic();
        Quadratic(double, double, double);
        Quadratic(const Quadratic&);
        Quadratic(Quadratic&&);
        Quadratic& operator=(const Quadratic&);
        Quadratic& operator=(Quadratic&&);
        ~Quadratic();
        double operator()(double) const;
};

Quadratic::Quadratic() : a(0), b(0), c(0) {}

Quadratic::Quadratic(double in_a, double in_b, double in_c)
    : a(in_a), b(in_b), c(in_c) {}

Quadratic::Quadratic(const Quadratic &copy_obj)
    : a(copy_obj.a), b(copy_obj.b), c(copy_obj.c) {}

Quadratic::Quadratic(Quadratic &&move_obj)
    : a(move_obj.a), b(move_obj.b), c(move_obj.c)
{
    move_obj.a = 0;
    move_obj.b = 0;
    move_obj.c = 0;
}

Quadratic& Quadratic::operator=(const Quadratic &copy_obj)
{
    a = copy_obj.a;
    b = copy_obj.b;
    c = copy_obj.c;

    return *this;
}

Quadratic& Quadratic::operator=(Quadratic &&move_obj)
{
    a = exchange(move_obj.a, 0);
    b = exchange(move_obj.b, 0);
    c = exchange(move_obj.c, 0);

    return *this;
}

Quadratic::~Quadratic() {}

double Quadratic::operator()(double in_x) const
{
    return a*a*in_x + b*in_x + c;
}

int main(int argc, char const *argv[])
{
    const Quadratic f(1.0, 2.0, 3.0);
    const Quadratic g = f;
    std::cout << f(1.0) << " " << g(1.0) << "\n";

    return 0;
}
