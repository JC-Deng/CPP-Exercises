#include <iostream>

using TypeI = void (char *, int &);
using TypeII = void (*)(TypeI);
using TypeIII = void (TypeII *);
using TypeMID = void (*)(TypeIII);
using TypeIV = TypeMID* ();

using TypeMID2 = void (TypeIV);

TypeMID2 * Func(TypeMID2 * k)
{
    return k;
}

int main(int argc, char const *argv[])
{
    return 0;
}
