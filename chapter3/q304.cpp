// Reduced form is better in many ways. First, in my current
// approach, the numerator and denominator both grow very
// quick and will possibly overflow after a series of calculation.
// Also, when the rational number is reduced, we can easily
// compare two rationals without extra step.
#include <iostream>

class Rational
{
    private:
        using Integer = int;
        Integer numerator;
        Integer denominator;

    public:
        Rational();
        Rational(int, int);

        Rational(const Rational&);
        Rational(Rational&&);
        Rational& operator=(const Rational&);
        Rational& operator=(Rational&&);
        ~Rational();

        Rational& operator+=(const Rational&);
        Rational& operator-=(const Rational&);
        Rational& operator*=(const Rational&);
        Rational& operator/=(const Rational&);

        double ToDouble() const;

        friend Rational operator+(const Rational&, const Rational&);
        friend Rational operator-(const Rational&, const Rational&);
        friend Rational operator*(const Rational&, const Rational&);
        friend Rational operator/(const Rational&, const Rational&);
        
        friend std::ostream& operator<<(std::ostream&,
            const Rational&);
};

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num_arg, int deno_arg)
    : numerator(num_arg), denominator(deno_arg) {}

Rational::Rational(const Rational &copy_obj)
    : numerator(copy_obj.numerator),
    denominator(copy_obj.denominator) {}

Rational& Rational::operator=(const Rational &copy_obj)
{
    numerator = copy_obj.numerator;
    denominator = copy_obj.denominator;
    return *this;
}

Rational& Rational::operator=(Rational &&move_obj)
{
    numerator = std::move(move_obj.numerator);
    denominator = std::move(move_obj.denominator);
    return *this;
}

Rational::Rational(Rational &&move_obj)
    : numerator(std::move(move_obj.numerator)),
    denominator(std::move(move_obj.denominator)) {}

Rational::~Rational() {}

Rational& Rational::operator+=(const Rational& b)
{
    this -> numerator = this -> numerator*b.denominator
        + this -> denominator*b.numerator;
    this -> denominator *= b.denominator;
    return *this;
}

Rational& Rational::operator-=(const Rational& b)
{
    this -> numerator = this -> numerator*b.denominator
        - this -> denominator*b.numerator;
    this -> denominator *= b.denominator;
    return *this;
}

Rational& Rational::operator*=(const Rational& b)
{
    this -> numerator *= b.numerator;
    this -> denominator *= b.denominator;
    return *this;
}

Rational& Rational::operator/=(const Rational& b)
{
    this -> numerator *= b.denominator;
    this -> denominator *= b.numerator;
    return *this;
}

double Rational::ToDouble() const
{
    return double(this -> numerator)/double(this -> denominator);
}

Rational operator+(const Rational& a, const Rational& b)
{
    return Rational(a.numerator*b.denominator + a.denominator*b.numerator,
        a.denominator*b.denominator);
}

Rational operator-(const Rational& a, const Rational& b)
{
    return Rational(a.numerator*b.denominator - a.denominator*b.numerator,
        a.denominator*b.denominator);
}

Rational operator*(const Rational& a, const Rational& b)
{
    return Rational(a.numerator*b.numerator, a.denominator*b.denominator);
}

Rational operator/(const Rational& a, const Rational& b)
{
    return Rational(a.numerator*b.denominator,
        a.denominator*b.numerator);
}

std::ostream& operator<<(std::ostream& os, const Rational& o_obj)
{
    if (o_obj.numerator*o_obj.denominator < 0)
    {
        os << '-';
    }
    os << (o_obj.numerator >= 0 ? o_obj.numerator : -o_obj.numerator)
        << '/' << (o_obj.denominator >= 0 ?
        o_obj.denominator : -o_obj.denominator);
    return os;
}

int main(int argc, char const *argv[])
{
    Rational test_a(-2, 3), test_b(4, 5);
    Rational copy_a(test_a), copy_b(test_b);

    std::cout << test_a << '+' << test_b << '\n'
        << test_a + test_b << '\n';
    std::cout << copy_a << '-' << copy_b << '\n'
        << copy_a - copy_b << '\n';

    Rational move_a(std::move(test_a)), move_b(std::move(test_b));
    
    std::cout << move_a << '*' << move_b << '\n'
        << move_a*move_b << '\n';
    std::cout << '(' << move_a << ')' << '/' 
        << '(' << move_b << ')' << '\n'
        << move_a/move_b << '\n';
    
    std::cout << move_a << "+=6/7" << '\n'
        << (move_a += Rational(6, 7)) << '\n';
    std::cout << move_a << "-=0/1" << '\n'
        << (move_a -= Rational(0, 1)) << '\n';
    std::cout << move_a << "*=3/4" << '\n'
        << (move_a *= Rational(3, 4)) << '\n';
    std::cout << move_a  << "/=(2/5)" << '\n'
        << (move_a /= Rational(2, 5)) << '\n';
    
    std::cout << move_a.ToDouble() << '\n';

    return 0;
}
