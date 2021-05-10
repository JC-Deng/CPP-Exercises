#include <iostream>
#include <cassert>
#include <cstring>

void CopyIntS(const int *p_source, int num_of_ints, int *p_target)
{
    while (num_of_ints-- > 0)
    {
        *p_target++ = *p_source++;
    }
}

int main(int argc, char const *argv[])
{
    const int src[4] = {1, 2, 3, 4};
    int dst[4] = {0, 0, 0, 0};

    CopyIntS(src, 4, dst);
    assert(!memcmp(src, dst, sizeof(src)));
    
    return 0;
}
