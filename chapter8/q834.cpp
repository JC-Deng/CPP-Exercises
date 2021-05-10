#include <algorithm>
#include <functional>
#include <random>
#include <utility>
#include <vector>

std::vector<float> make_vector_1()
{
  return std::vector<float>(42, 42.0f);
}

std::vector<float> make_vector_2()
{
  std::default_random_engine gen;
  std::uniform_real_distribution<float> dist(0.0f, 10.0f);
  std::vector<float> a(10);
  std::generate(a.begin(), a.end(), [&](){return dist(gen);});
  return a;
}

std::vector<float> make_vector_3()
{
  return std::move(std::vector<float>{1.0f, 2.0f, 3.0f, 4.0f});
}

float sum_1(const std::vector<float>& a)
{
  return std::accumulate(a.begin(), a.end(), 0.0f);
}

float sum_2(std::vector<float> a)
{
  return std::accumulate(a.begin(), a.end(), 0.0f);
}

std::vector<float> a(make_vector_1()); // Mandatory copy elision.
std::vector<float> b(make_vector_2()); // Non-mandatory copy elision.
std::vector<float> c(make_vector_3()); // Not possible to elide copy/move. 1 move happens.

int main()
{
  std::vector<float> v(a); // 1 copy happens.
  std::vector<float> w(std::move(c)); // 1 move happens.
  std::vector<float> x(make_vector_1()); // Mandatory copy elision.
  std::vector<float> y(make_vector_2()); // Non-mandatory copy elision.
  std::vector<float> z(make_vector_3()); // 1 move happens.
  v = std::move(b); // 1 move happens.
  w = v; // 1 copy happens.
  w = make_vector_1();
  // Copy in passing object from func to temporary object is
  // elided(mandatory). Then a move happens from temporary object to w.
  w = make_vector_2(); // 1 non-mandatory copy elision. 1 move to w.
  w = make_vector_3(); // 1 move from func to temporary object. 1 move to w.
  float s;
  s = sum_1(make_vector_1()); // Mandatory copy elision.
  s = sum_2(make_vector_1()); // Mandatory copy elision.
}