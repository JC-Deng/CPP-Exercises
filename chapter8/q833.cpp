#include <list>
#include <mutex>
#include <set>
#include <utility>
#include <vector>

// According to https://en.cppreference.com/w/cpp/language/copy_elision,
// NRVO is not guaranteed to omit copy/move since it has side effects.
// Returned prvalue instead.
std::set<int> make_set()
{
  // std::set<int> s{1, 2, 4, 8};
  // return s;
  return std::set<int>{1, 2, 4, 8};
}

std::vector<int> make_vector(bool flag)
{
  // std::vector<int> a{1, 2, 3, 4};
  // std::vector<int> b{5, 6, 7, 8};
  // if (flag) {
  //   return a;
  // } else {
  //   return b;
  // }
  if (flag) {
    return std::vector<int>{1, 2, 3, 4};
  } else {
    return std::vector<int>{5, 6, 7, 8};
  }
}

std::list<std::mutex> make_mutexes(int n)
{
  // std::move() will prevent copy elision from happening,
  // therefore it is removed.
  // return std::move(std::list<std::mutex>(n));
  return std::list<std::mutex>(n);
}

int main(int argc, char const *argv[])
{
  return 0;
}
