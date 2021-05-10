#include <iostream>
 #include <vector>
 #include <set>

 int main() {
 // The following two lines are the only important ones:
 auto cmp = [](int* x, int* y){return *x < *y;};
 std::set<int*, decltype(cmp)> s(cmp);

 // Just for something to do:
 // Print the elements of v in sorted order with
 // duplicates removed.
 std::vector<int> v = {4, 1, 3, 2, 1, 1, 1, 1};
 for (auto& x : v) {
 s.insert(&x);
 }
 for (auto x : s) {
 std::cout << *x << '\n';
 }
 }
