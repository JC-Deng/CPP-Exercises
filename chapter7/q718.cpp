#include <atomic>
#include <thread>
#include <chrono>
#include <iostream>

std::atomic_int data = 0;
std::atomic_bool spin_lock = false;

void writer()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    data = 42;
    spin_lock = true;
}

void reader()
{
    while (!spin_lock);
    std::cout << data << '\n';
}

int main(int argc, char const *argv[])
{
    std::thread tr{reader};
    std::thread tw{writer};
    tr.join();
    tw.join();
    return 0;
}
