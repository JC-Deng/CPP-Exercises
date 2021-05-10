#include <iostream>
#include <memory>

std::size_t string_length(const char* s)
{
    std::size_t n = 0;
    while (*s != '\0') {
        ++s;
        ++n;
    }
    return n;
}

std::size_t StrLen(const std::unique_ptr<char []> &s)
{
    std::size_t res = 0;
    while (s[res] != '\0') {
        res++;
    }
    return res;
}

std::unique_ptr<char []>&
StrCpy(std::unique_ptr<char []> &d,
    const char *s, int off_set = 0)
{
    int i = 0;
    while((d[i + off_set] = s[i]) != '\0') {
        ++i;
    }
    d[i + off_set] = '\0';
    return d;
}

std::unique_ptr<char []>&
StrCpy(std::unique_ptr<char []> &d,
    const std::unique_ptr<char []> &s, int off_set = 0)
{
    int i = 0;
    while((d[i + off_set] = s[i]) != '\0') {
        ++i;
    }
    d[i + off_set] = '\0';
    return d;
}

auto StrDuplicate(const std::unique_ptr<char []> &s)
{
    auto res = std::make_unique<char []>(StrLen(s) + 1);
    StrCpy(res, s);
    return res;
}

auto StrConcat(const char* first, const char* second)
{
    std::size_t first_len = string_length(first);
    std::size_t second_len = string_length(second);
    char* result = new char[first_len + second_len + 1];
    auto res = std::make_unique<char []>(
        first_len + second_len + 1);
    StrCpy(res, first);
    StrCpy(res, second, first_len);
    return res;
}

int main() {
    auto s = StrConcat("Hello, ", "World!");
    auto t = StrDuplicate(s);
    for (int i = 0; t[i] != '\0'; i++) {
        std::cout << t[i];
    }
    std::cout << '\n';
}