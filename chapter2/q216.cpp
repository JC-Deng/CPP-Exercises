int main(int argc, char const *argv[])
{
    const char a = 'a';

    // Pointing a non-const char * to a const char
    // char *c = a;
    const char *c = &a;

    const int i = 42;
    // Increment of read-only reference.
    // auto &j = i;
    // ++j;
    int j = i + 1;

    return 0;
}
