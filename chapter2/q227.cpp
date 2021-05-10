#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;

    for (int i = 1; i < argc; i++)
    {
        ifstream q227_file (argv[i]); 
        if (q227_file.is_open())
        {
            while (getline(q227_file, line))
            {
                cout << line << '\n';
            }
            q227_file.close();
        }
        else
        {
            cout << "Error when opening file.";
        }
    }

    return 0;
}
