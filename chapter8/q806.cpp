#include <iostream>

typedef char& LvRefChar;
typedef const char& LvRefConstChar;
typedef char&& RvRefChar;
typedef const char&& RvRefConstChar;

typedef LvRefChar& T1; // T1, T2, T3, T4 are all lvalue reference to char.
typedef const LvRefChar& T2;
typedef LvRefChar&& T3;
typedef const LvRefChar&& T4;

typedef LvRefConstChar& T5; // T5, T6, T7, T8 are all const lvalue reference to char.
typedef const LvRefConstChar& T6;
typedef LvRefConstChar&& T7;
typedef const LvRefConstChar&& T8;

typedef RvRefChar& T9; // T9, T10 are lvalue reference to char.
typedef const RvRefChar& T10;
typedef RvRefChar&& T11; // T11, T12 are rvalue reference to char.
typedef const RvRefChar&& T12;

typedef RvRefConstChar& T13; // T13, T14 are const lvalue reference to char.
typedef const RvRefConstChar& T14;
typedef RvRefConstChar&& T15; // T15, T16 are const rvalue reference to char.
typedef const RvRefConstChar&& T16;

int main(int argc, char const *argv[])
{
  char test = 'a';
  return EXIT_SUCCESS;
}
