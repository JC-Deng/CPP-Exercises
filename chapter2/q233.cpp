#include <iostream>
// Method 1: Use specific using statement.
using std::cout;
// Method 2: Use alias to refer to a type or an object, to avoid a long identifier.
auto &cout_alias = std::cout;

int main(int argc, char const *argv[])
{
    // std::cout << "Hello, World!\n";
    cout << "Hello, World!\n";
    cout_alias << "Hello, World!\n";
    
    return 0;
}

/* Namespace std includes all identifiers in the C++ standard library.
It includes hundreds of identifiers, some of which are not familiar to
many developers. If namespace std is used, too many identifiers are
imported all at once, and there is a very high risk of name conflicts.
Therefore, using namespace std should be avoided since there are some
good alternatives to this approach. */