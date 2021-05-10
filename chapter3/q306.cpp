// Return private members of a class will expose what is supposed to
// be hidden for the users. Therefore, it's not desirable.
#include <iostream>

class RealPoint2
{
    public:
        // The coordinate type, in case we want to change it later.
        typedef double Real;
        // Create a new point with coordinates (0, 0).
        RealPoint2();
        // Create a new point with coordinates (x, y).
        RealPoint2(const Real&, const Real&);

        // Obtain a reference to the x-coordinate of the point.
        Real& X_Coordinate();
        const Real& X_Coordinate() const;

        // Obtain a reference to the y-coordinate of the point.
        Real& Y_Coordinate();
        const Real& Y_Coordinate() const;

        // Add/subtract displacement to/from point (i.e., translate point).
        RealPoint2& operator+=(const RealPoint2&);
        RealPoint2& operator-=(const RealPoint2&);

        // Write a point to an output stream.
        friend std::ostream& operator<<(std::ostream&, const RealPoint2&);
        
        // Read a point from an input stream.
        friend std::istream& operator>>(std::istream&, RealPoint2&);

    private:
        Real x;
        Real y;
 };

RealPoint2::RealPoint2() : x(0), y(0) {}

RealPoint2::RealPoint2(const Real& xi, const Real& yi) : x(xi), y(yi) {}

RealPoint2::Real& RealPoint2::X_Coordinate()
{
    Real& x_ref = x;
    return x_ref;
}
const RealPoint2::Real& RealPoint2::X_Coordinate() const
{
    const Real& x_ref_const = x;
    return x_ref_const;
}

RealPoint2::Real& RealPoint2::Y_Coordinate()
{
    Real& y_ref = y;
    return y_ref;
}
const RealPoint2::Real& RealPoint2::Y_Coordinate() const
{
    const Real& y_ref_const = y;
    return y_ref_const;
}

RealPoint2& RealPoint2::operator+=(const RealPoint2& p)
{
    x += p.x;
    y += p.y;
    return *this;
}

RealPoint2& RealPoint2::operator-=(const RealPoint2& p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const RealPoint2& p)
{
    std::cout << "x coordinate is: " << p.x << '\n'
        << "y coordinate is: " << p.y << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, RealPoint2& p)
{
    std::cin >> p.x >> p.y;
    return is;
}

int main(int argc, char const *argv[])
{
    RealPoint2 test_point;

    while (std::cin >> test_point)
    {
        test_point += RealPoint2(1.5, -1.5);
        std::cout << test_point;
    }
    if (!std::cin.eof())
    {
        return 1;
    }
            
    return 0;
}
