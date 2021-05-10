#include <iostream>

double SafeDivide(double numerator, double denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Devided by zero.");
    }
    else 
    {
        return numerator/denominator;
    }
}

int main(int argc, char const *argv[])
{
    double user_numerator, user_denominator;

    std::cout << "Type in numerator and denominator:" << std::endl;
    while (true)
    {
        try
        {
            std::cin >> user_numerator >> user_denominator;
            std::cout << "Result: "
                << SafeDivide(user_numerator, user_denominator)
                << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error. " << e.what() << '\n';
        }
        
    }
    
    return 0;
}
