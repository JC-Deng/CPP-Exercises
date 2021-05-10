#include <iostream>
#include <vector>
#include <utility>
#include <string>

std::vector<float>& half(std::vector<float>& a)
{
  for (auto&& x : a) {
    x *= 0.5f;
    // 0.5f prvalue
    // x *= 0.5f lvalue
  }
  return a;
}

std::vector<float> get_data()
{
  return std::vector<float>{1.0f, 0.5f, 0.25f, 0.125f};
  // std::vector<float>{1.0f, 0.5f, 0.25f, 0.125f} prvalue
}

int main() {
  std::vector<float> a{1.0f, 2.0f, 3.0f};
  std::vector<float> b(std::move(a));
  float x = 0.0f;
  float y = 42.0f;
  float* p = nullptr;
  // nullptr prvalue
  a = std::move(b);
  // std::move prvalue
  // std::move(b) xvalue
  // a = std::move(b) lvalue
  b = {1.0f, 2.0f, 3.0f};
  // {1.0f, 2.0f, 3.0f} prvalue
  half(b);
  // half(b) lvalue
  x += (- a[0] + 2.0f * a[1] - 42) / 3.0f;
  // 42 prvalue
  // - a[0] prvalue
  // - a[0] + 2.0f * a[1] - 42 prvalue
  x *= y + y;
  // y + y prvalue
  p = a.data();
  // a.data() prvalue
  x = *p + 1.0f;
  // *p lvalue
  // x = *p + 1.0f lvalue
  b = get_data();
  // get_data() prvalue
  std::cout << a[0] << '\n';
  // std::cout prvalue
  // std::cout << a[0] lvalue
  // '\n' prvalue
  std::vector<float>::iterator i = a.begin();
  std::vector<float>::iterator j;
  ++i;
  // ++i lvalue
  j = i;
  // j = i lvalue
  i--;
  // i-- prvalue
  std::cout << j - i << '\n';
  // j - i prvalue
  std::cout << *i << "\n";
  // *i lvalue
  // "\n" lvalue(a const char*)
}