#include <iostream>

template <class T>
class IsVoid
{
    public:
        using ValueType = bool;
        static ValueType value;
};

template <class T>
typename IsVoid<T>::ValueType IsVoid<T>::value =
    std::is_same<void, typename std::remove_cv_t<T>>::value;

int main()
{
    std::cout << std::boolalpha
        << IsVoid<void>::value << "\n"
        << IsVoid<const void>::value << "\n"
        << IsVoid<volatile void>::value << "\n"
        << IsVoid<const volatile void>::value << "\n"
        << IsVoid<int>::value << "\n"
        << IsVoid<const double>::value << "\n"
        << IsVoid<volatile char>::value << "\n"
        << IsVoid<const volatile long long>::value << "\n"
        << IsVoid<void (*)(int, int)>::value << "\n";
}
