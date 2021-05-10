// These are examples I found in http://eel.is/c++draft/diff.iso.
// Can be compiled using gcc but not g++.
#include <stdio.h>

// Converting void* to a pointer-to-object type requires casting
// in C++ but is valid in C.
char a[10];
void* b = a;

void foo() {
  char* c = b;
  printf("Successfully called.\n");
}

// In C++, types can only be defined in declarations, not in expressions.
// In C, a sizeof expression or cast expression may define a new type.
p = (void*)(struct x {int i;} *)0;

int main(int argc, char const *argv[])
{
  foo();
  p;
  return 0;
}
