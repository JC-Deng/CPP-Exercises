#include <iostream>
#include <memory>

std::unique_ptr<char[]> GetBuffer(std::size_t size)
{
    return std::make_unique<char[]>(size);
}

int main(int argc, char const *argv[])
{
    auto p = GetBuffer(5);
    p[0] = 'a';
    std::cout << p[0] << '\n';
    return 0;
}
