#include <iostream>
#include <string>
#include <vector>
#include <memory>

std::unique_ptr<std::string> GetWord(std::istream &is)
{
    std::string s;
    if (is >> s) {
        auto s_ptr = std::make_unique<std::string>(s);
        return s_ptr;
    } else {
        return nullptr;
    }
}

int main(int argc, char const *argv[])
{
    std::unique_ptr<std::string> s;
    std::vector<std::unique_ptr<std::string>> v;
    while (s = GetWord(std::cin)) {
        v.push_back(std::move(s));
    }
    for (auto &x : v) {
        std::cout << *x << '\n';
    }
    return 0;
}
