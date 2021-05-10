#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<double> vec(21);
    std::generate(vec.begin(), vec.end(),
        []{static int i = -10; return i += 10;});
    std::cout.width(8);
    std::cout << "Pounds";
    std::cout.width(10);
    std::cout << "Kilograms" << '\n';
    std::for_each(vec.begin(), vec.end(),
        [](double &x)
        {
            std::cout.width(8);
            std::cout << std::fixed << std::setprecision(2) << x;
            std::cout.width(10);
            std::cout << std::fixed << std::setprecision(2)
                << 0.453592*x << '\n';
        });
    return 0;
}
