#include <iostream>
#include <string>
using std::string;

class omg {};
class yikes {};

// Wrapper class that indicates the destruction of std::string.
class my_string : public string
{
    public:
        my_string(const char *ptr) : string(ptr) {}
        ~my_string() {
            std::cout << this->c_str() << '\n';
        }
};

void func_1(my_string s) // No.2 s copied. No.2 s 5th in stack.
                         // No.3 s copied. 5th in stack.
{
    my_string alpha("alpha"); // alpha 6th in stack.
                              // New 6th constructed.
    if (s == "omg") { 
        my_string beta("beta"); // beta 7th in stack.
        throw omg();
        // Throws. Destructing for the first time, 7, 6, 5 destructed.
        my_string gamma("gamma");
    } else if (s == "yikes") { 
        my_string delta("delta"); // New 7th constructed.
        throw yikes();  // New 7, 6, 5 destructed.
        my_string epsilon("epsilon");
    }
    my_string zeta("zeta");
}

void func_2(my_string s) // No.1 s copied. No.1 s is 2nd in stack.
{
    my_string eta("eta"); // eta is 3rd in stack.
    try {
        my_string theta("theta"); // theta 4th in stack.
        func_1(s); // Throws. 4 destroyed for the first time.
        my_string iota("iota");
    } catch (const omg& e) {
        my_string kappa("kappa"); // New 4th constructed.
        func_1("yikes"); // New 4the destructed.
        my_string lambda("lambda");
    }
    my_string mu("mu");
}

int main()
try {
    my_string nu("nu"); // nu constructed. 1st in stack.
    func_2("omg"); // Throws. 3, 2, 1 destructed.
    my_string xi("xi");
} catch (...) {
    std::cerr << "exception\n"; // Finally, "exception" is displayed.
}
