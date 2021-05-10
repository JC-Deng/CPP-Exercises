#include <iostream>

// A noexcept Quadratic function implementation.
template <class T>
T Quadratic(const T &x, const T &a, const T &b, const T &c)
noexcept(std::is_nothrow_move_constructible<T>::value &&
    noexcept(a*x*x + b*x + c))
{
    return a*x*x + b*x + c;
}

// Wrapper class of int for investigation into construction process.
class WrapperInt
{
    private:
        int content;
    
    public:
        WrapperInt() = delete;
        WrapperInt(int a) noexcept : content(a) {
            std::cout << "Parameter construction.\n";
        }
        WrapperInt(const WrapperInt &wi) noexcept : content(wi.content) {
            std::cout << "Copy construction.\n";
        }
        WrapperInt(WrapperInt &&wi) noexcept : content(wi.content) {
            std::cout << "Move construction.\n";
        }
        WrapperInt operator*(const WrapperInt &wi) const noexcept{
            auto t = WrapperInt(content * wi.content);
            auto m = t + WrapperInt(1);
            return m;
        }
        WrapperInt operator+(const WrapperInt &wi) const noexcept{
            return WrapperInt(content + wi.content);
        }
        friend std::ostream& operator<<(std::ostream &os, const WrapperInt &wi) {
            std::cout << wi.content;
            return os;
        }
};

int main(int argc, char const *argv[])
{
    std::cout << Quadratic(WrapperInt(1), WrapperInt(2),
        WrapperInt(3), WrapperInt(4)) << '\n';
    return 0;
} 
