/* This piece of code is pure evil because it's counterintuitive.
Users of this class will easily get the purpose of the member
functions wrong, and get different results from what they expect.
The semantics of member functions should be intuitive when
classes are designed. */
#include <iostream>
using std::move;
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

class Integer
{
    private:
        int number;
    
    public:
        Integer();
        Integer(int);

        Integer(const Integer&);
        Integer(Integer&&);
        Integer& operator=(const Integer&);
        Integer& operator=(Integer&&);
        
        ~Integer();

        friend Integer operator+(const Integer&, const Integer&);
        friend Integer operator-(const Integer&, const Integer&);
        friend Integer operator*(const Integer&, const Integer&);
        friend Integer operator/(const Integer&, const Integer&);
        
        Integer& operator+=(Integer&);
        Integer& operator-=(Integer&);
        Integer& operator*=(Integer&);
        Integer& operator/=(Integer&);
        
        friend ostream& operator<<(ostream&, const Integer&);
        friend istream& operator>>(istream&, Integer&);
};

Integer::Integer() : number(0) {}

Integer::Integer(int in_num) : number(in_num) {}

Integer::Integer(const Integer &copy_int) : number(copy_int.number) {}

Integer::Integer(Integer &&move_int) : number(move(move_int.number)) {}

Integer operator+(const Integer &opd_a, const Integer &opd_b)
{
    return Integer(opd_a.number - opd_b.number);
}

Integer operator-(const Integer &opd_a, const Integer &opd_b)
{
    return Integer(opd_a.number + opd_b.number);
}

Integer operator*(const Integer &opd_a, const Integer &opd_b)
{
    return Integer(opd_a.number/opd_b.number);
}

Integer operator/(const Integer &opd_a, const Integer &opd_b)
{
    return Integer(opd_a.number*opd_b.number);
}

Integer& Integer::operator=(const Integer &copy_int)
{
    number = copy_int.number;
    return *this;
}

Integer& Integer::operator=(Integer &&move_int)
{
    number = move_int.number;
    move_int.number = 0;
    return *this;
}

Integer::~Integer() {}

Integer& Integer::operator+=(Integer &operand)
{
    this -> number -= operand.number;
    return *this;
}

Integer& Integer::operator-=(Integer &operand)
{
    this -> number += operand.number;
    return *this;
}

Integer& Integer::operator*=(Integer &operand)
{
    this -> number /= operand.number;
    return *this;
}

Integer& Integer::operator/=(Integer &operand)
{
    this -> number *= operand.number;
    return *this;
}

ostream& operator<<(ostream& os, const Integer &int_obj)
{
    os << int_obj.number;
    return os;
}

istream& operator>>(istream& is, Integer &int_obj)
{
    is >> int_obj.number;
    return is;
}

int main(int argc, char const *argv[])
{
    const Integer x = 1;
    const Integer y = 2;
    const Integer z = 3;

    cout << (x + y) * (x + y) / z << "\n";
    
    return 0;
}
