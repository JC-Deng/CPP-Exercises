#include <iostream>
#include <cstring>
#include <memory>

// Copy a C-style string.
std::unique_ptr<char []>&
StrCpy(std::unique_ptr<char []> &res,
    const char *s, int off_set = 0)
{
    int i = 0;
    while((res[i + off_set] = s[i]) != '\0') {
        ++i;
    }
    res[i + off_set] = '\0';
    return res;
}

// Duplicate a C-style string.
auto StrDuplicate(const char *s)
{
    std::size_t n = std::strlen(s);
    auto res = std::make_unique<char []>(n + 1);
    StrCpy(res, s);
    return res;
}

// Read character data from an input stream and return it.
std::unique_ptr<char []>
SourceData()
{
    char buffer[1024];
    if (std::cin.getline(buffer, sizeof(buffer))) {
        return StrDuplicate(buffer);
    } else {
        return nullptr;
    }
}

// Transform the character data and return the transformed data.
// (Map lowercase to uppercase.)
std::unique_ptr<char []>&
TransformData(std::unique_ptr<char []> &s)
{
    int i = 0;
    while (s[i] != '\0') {
        if (islower(s[i])) {
            s[i] = toupper(s[i]);
        }
        ++i;
    }
    return s;
}

// Write the character data to an output stream and then discard the data.
void SinkData(std::unique_ptr<char []> &s)
{
    int i = 0;
    while (s[i] != '\0') {
        std::cout << s[i];
        ++i;
    }
    std::cout << '\n';
}

int main()
{
    std::unique_ptr<char []> smart_s;
    while (smart_s = SourceData()) {
        TransformData(smart_s);
        SinkData(smart_s);
    }
}