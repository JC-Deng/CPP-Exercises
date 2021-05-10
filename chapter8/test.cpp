#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>

class TestClass
{
  public:
    std::vector<float> content{10};
    TestClass() {std::cout << "Constructed.\n";}
    TestClass(std::initializer_list<float> in) : content(in) {std::cout << "Constructed.\n";}
    TestClass(TestClass&) {std::cout << "Copied.\n";}
    TestClass(TestClass&&) {std::cout << "Moved.\n";}
    void operator=(const TestClass &opn)
    {
      std::cout << "Copied.\n";
    }
    void operator=(const TestClass &&opn)
    {
      std::cout << "Moved.\n";
    }
};

TestClass test_func()
{
  return TestClass{};
}

float test_sum(TestClass opn)
{
  return std::accumulate(opn.content.begin(), opn.content.end(), 0.0f);
}

int main(int argc, char const *argv[])
{
  float s;
  s = test_sum(test_func());
  return 0;
}
