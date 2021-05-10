#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace mine
{
    int strlen(const char *s)
    {
        int res = 0;
        while(*s++ != '\0')
        {
            res++;
        }
        
        return res;
    }
}

int main(int argc, char const *argv[])
{
    string std_s;
    cout << "Input string: " << endl;
    cin >> std_s;
    const char *s = std_s.data();
    
    cout << "The result of original strlen function: "
        << std::strlen(s) << endl;
    cout << "The result of mine::strlen function: "
        << mine::strlen(s) << endl;
    
    return 0;
}
