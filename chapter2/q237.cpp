int main(int argc, char const *argv[])
{
    const int ci = 42;
    int i = ci;
    auto& a = i; // int &
    auto& b = ci; // const int &
    auto&& c = 0; // int &&
    const auto&& d = 0; // const int &&
    auto e = &ci; // const int *
    auto f = &i; // int *
    auto const g = &i; // int * const
    const auto h = &i; // int * const

    return 0;
}
