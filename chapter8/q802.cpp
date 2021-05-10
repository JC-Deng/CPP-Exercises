#include <iostream>

double getDouble()
{
  return 42.0;
}

int main(int argc, char const *argv[])
{
  double getDouble();
  const double get_const();
  const double cd = 42.0;
  double d = cd;

  double& lr1 = d; // Legal.
  // double& lr2 = cd; Const variable binded to non-const reference.
  // double& lr3 = getDouble(); Non-const prvalue binded to reference.

  const double& lrc1 = d; // Legal.
  const double& lrc2 = cd; // Legal.
  const double& lrc3 = 42.0; // Legal.

  // double&& rr1 = d; lvalue binded to rvalue reference.
  // double&& rr2 = cd; lvalue binded to rvalue refernce and const missed.
  double&& rr3 = getDouble(); // Legal.

  // const double&& rrc1 = d; lvalue binded to rvalue reference.
  // const double&& rrc2 = cd; lvalue binded to rvalue reference.
  const double&& rrc3 = 42.0; // Legal.
      
  return 0;
}
