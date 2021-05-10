#include <utility>
#include <vector>
#include <iostream>

// This is not a good practice to return std::move(T), since
// it will break the condition of NRVO and prevent the compiler
// to perform copy elision. When return T meets the conditions
// of copy elision, copy elision will be guaranteed so there's
// no need to return std::move(T).
std::vector<float> get_data()
{
  return std::vector<float>{1.0f, 0.5f, 0.25f, 0.125f};
}

int main(int argc, char const *argv[])
{
  auto test_data = get_data();
  std::cout << test_data[1] << '\n';
  return 0;
}
