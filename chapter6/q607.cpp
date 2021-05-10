#include <iostream>
#include <vector>
#include <algorithm>

void Process(int x)
{
    if (x == 1) {
        throw x;
    }
    if (x == 2) {
        throw "yikes";
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> v{0, 1, 2, 3};
    for (auto x : v) {
        try {
            Process(x);
            std::cout << "okay\n";
        }
        catch (int &e) {
            std::cout << "int " << e << '\n';
        }
        catch (const char *e) {
            std::cout << "const char* " << e << '\n';
        }
    }
    return 0;
}
