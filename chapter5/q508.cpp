/* When a new item is pushed into a vector and surpasses
its capacity, the vector will be reallocated double the
space and move all the current items to it. This process
will cost time, but since it has an exponential increase
rate the cost is well managed. So the two getVector
functions have some difference in performance but the
difference is not very big.
*/
#include <vector>
#include <iostream>
#include <chrono>

std::vector<int> getVector1(int n)
{
    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
        result.push_back(i);
    }
    return result;
}

std::vector<int> getVector2(int n)
{
    std::vector<int> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
        result.push_back(i);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    auto time_1 = std::chrono::high_resolution_clock::now();
    getVector1(16777216);
    auto time_2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<
        std::chrono::duration<double>>(time_2 - time_1).count() << '\n';
    getVector2(16777216);
    auto time_3 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<
        std::chrono::duration<double>>(time_3 - time_2).count() << '\n';
    return 0;
}