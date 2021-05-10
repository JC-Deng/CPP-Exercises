#include <iostream>
#include <string>
#include <memory>

int CStrLen(const std::unique_ptr<char []> &a)
{
    int res = 0;
    while (a[res] != '\0')
    {
        res++;
    };
    return res;
}

std::unique_ptr<char[]> BetterConcat(
    const std::unique_ptr<char []> &sub_a,
    const std::unique_ptr<char []> &sub_b)
{
    int len_a = CStrLen(sub_a);
    int len_b = CStrLen(sub_b);

    auto res = std::make_unique<char []>(len_a + len_b + 1);

    int i = 0;
    while (sub_a[i] != '\0') {
        res[i] = sub_a[i];
        i++;
    }
    int j = 0;
    while (sub_b[j] != '\0') {
        res[j + i] = sub_b[j];
        j++;
    }
    res[j + i] = '\0';
    return res;
}

int main(int argc, char const *argv[])
{
    const char *s_a = "hello, ";
    const char *s_b = "world!";
    auto a = std::make_unique<char []>(8);
    for (int i = 0; i < 8; i++) {
        a[i] = s_a[i];
    }
    auto b = std::make_unique<char []>(7);
    for (int i = 0; i < 7; i++) {
        b[i] = s_b[i];
    }
    auto res = BetterConcat(a, b);
    int i = 0;
    while (res[i] != '\0') {
        std::cout << res[i];
        i++;
    }
    std::cout << '\n';
    return 0;
}
