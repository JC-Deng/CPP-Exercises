#include <iostream>
#include <future>
#include <vector>
#include <cmath>

bool IsPrime(long long opn)
{
    long long sqare_rt = sqrt(opn);
    for (long long i = 3; i <= sqare_rt; i += 2) {
        if (opn%i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::vector<std::future<bool>> futures;
    for (long long i = 0; i < 4; ++i) {
        long long opn = 4'294'967'291 + 2*i;
        futures.emplace_back(std::async(
            std::launch::async, IsPrime, opn));
    }
    for (long long i = 0; i < 4; ++i) {
        long long opn = 4'294'967'291 + 2*i;
        bool res = futures[i].get();
        std::cout << "Is " << opn << " prime? ";
        if (res) {
            std::cout << "Ture.\n";
        } else {
            std::cout << "False.\n";
        }
    }

    futures.clear();
    std::packaged_task<bool(long long)> task(IsPrime);
    for (long long i = 0; i < 4; ++i) {
        long long opn = 4'294'967'291 + 2*i;
        task(opn);
        futures.emplace_back(task.get_future());
        task.reset();
    }
    for (long long i = 0; i < 4; ++i) {
        long long opn = 4'294'967'291 + 2*i;
        bool res = futures[i].get();
        std::cout << "Is " << opn << " prime? ";
        if (res) {
            std::cout << "Ture.\n";
        } else {
            std::cout << "False.\n";
        }
    }

    return 0;
}
