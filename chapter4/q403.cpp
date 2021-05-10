// Return private members of a class will expose what is supposed to
// be hidden for the users. Therefore, it's not desirable.
#include <iostream>

// class RealPoint2
template <class T> class Point2
// {
{
    public:
        Point2();
        Point2(const T&, const T&);
        T& X_Coordinate();
        const T& X_Coordinate() const;
        T& Y_Coordinate();
        const T& Y_Coordinate() const;
        Point2& operator+=(const Point2&);
        Point2& operator-=(const Point2&);


        template <class TF> friend std::ostream&
            operator<<(std::ostream&, const Point2<TF>&);
        template <class TF> friend std::istream&
            operator>>(std::istream&, Point2<TF>&);

    private:
        T x;
        T y;
};


// RealPoint2::RealPoint2() : x(0), y(0) {}
template <class T> Point2<T>::Point2() : x(0), y(0) {}

// RealPoint2::RealPoint2(const Real& xi, const Real& yi) : x(xi), y(yi) {}
template <class T> Point2<T>::Point2(const T& xi, const T& yi)
    : x(xi), y(yi) {}

// RealPoint2::Real& RealPoint2::X_Coordinate()
// {
//     Real& x_ref = x;
//     return x_ref;
// }
template <class T> T& Point2<T>::X_Coordinate()
{
    T& x_ref = x;
    return x_ref;
}
template <class T> const T& Point2<T>::X_Coordinate() const
{
    const T& x_ref_const = x;
    return x_ref_const;
}

// const RealPoint2::Real& RealPoint2::X_Coordinate() const
// {
//     const Real& x_ref_const = x;
//     return x_ref_const;
// }

// RealPoint2::Real& RealPoint2::Y_Coordinate()
// {
//     Real& y_ref = y;
//     return y_ref;
// }
template <class T> T& Point2<T>::Y_Coordinate()
{
    T& y_ref = y;
    return y_ref;
}
// const RealPoint2::Real& RealPoint2::Y_Coordinate() const
// {
//     const Real& y_ref_const = y;
//     return y_ref_const;
// }

template <class T> const T& Point2<T>::Y_Coordinate() const
{
    T& y_ref_const = y;
    return y_ref_const;
}

// RealPoint2& RealPoint2::operator+=(const RealPoint2& p)
// {
//     x += p.x;
//     y += p.y;
//     return *this;
// }

template <class T> Point2<T>& Point2<T>::operator+=(const Point2<T>& p)
{
    x += p.x;
    y += p.y;
    return *this;
}

// RealPoint2& RealPoint2::operator-=(const RealPoint2& p)
// {
//     x -= p.x;
//     y -= p.y;
//     return *this;
// }

template <class T> Point2<T>& Point2<T>::operator-=(const Point2<T>& p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}

// std::ostream& operator<<(std::ostream& os, const RealPoint2& p)
// {
//     std::cout << "x coordinate is: " << p.x << '\n'
//         << "y coordinate is: " << p.y << '\n';
//     return os;
// }

template <class T> std::ostream& operator<<(std::ostream& os, const Point2<T>& p)
{
    std::cout << "x coordinate is: " << p.x << '\n'
        << "y coordinate is: " << p.y << '\n';
    return os;
}

// std::istream& operator>>(std::istream& is, RealPoint2& p)
// {
//     std::cin >> p.x >> p.y;
//     return is;
// }

template <class T> std::istream& operator>>(std::istream& is, const Point2<T>& p)
{
    std::cin >> p.x >> p.y;
    return is;
}

int main(int argc, char const *argv[])
{
    Point2<int> test_obj_int(1, 2);
    Point2<double> test_obj_double(1.1, 2.2);

    test_obj_double += Point2<double>(2.1, 2.2);
    std::cout << test_obj_double;
    int& ref_int = test_obj_int.X_Coordinate();
    ref_int++;
    std::cout << test_obj_int.X_Coordinate() << '\n';

    
    return 0;
}
