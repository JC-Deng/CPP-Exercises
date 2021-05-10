#include<iostream>

int main(int argc, char const *argv[])
{
    struct Widget {};
    using test_type = void (*)(int, int);
    const std::type_info &t_info = typeid(int);
    const std::type_info &d_info = typeid(double);
    const std::type_info &f_info = typeid(test_type);
    const std::type_info &s_info = typeid(Widget);
    std::cout << t_info.name() << '\n'
        << d_info.name() << '\n'
        << f_info.name() << '\n'
        << s_info.name() << '\n';
    return 0;
}
