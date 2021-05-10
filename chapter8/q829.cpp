#include <iostream>

// The asymtotic time complexity is O(logN)
// The asymtotic space complexity is O(N)
template <class T>
T recursive_sum(const T *first, std::size_t n)
{
  if (n >= 2) {
    std::size_t m = n/2;
    return recursive_sum(first, m) +
      recursive_sum(first + m, n - m);
  } else {
    return *first;
  }
}

int main(int argc, char const *argv[])
{
  return 0;
}
