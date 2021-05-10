#include <iostream>

bool CopyStream(std::istream &in, std::ostream &out)
{
    std::string s;
    while (std::getline(in, s))
    {
        if (!(out << s)) {
            return false;
        }
    }
    if (!in.eof()) {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    CopyStream(std::cin, std::cout);
    return 0;
}
