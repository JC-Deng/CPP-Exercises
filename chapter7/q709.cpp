#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;

void SquareWork() {
    for (int i = -100; i <= 100; ++i) {
        std::lock_guard<std::mutex> lock(m);
        std::cout << "The sqaure of i is " << i*i << ".\n";
    }
}

void CubeWork() {
    for (int i = -100; i <= 100; ++i) {
        std::lock_guard<std::mutex> lock(m);
        std::cout << "The cube of i is " << i*i*i << ".\n";
    }
}

int main(int argc, char const *argv[])
{
    std::thread square_work(SquareWork);
    std::thread cube_work(CubeWork);
    square_work.join();
    cube_work.join();
    return 0;
}
