#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex io_m;

void t1()
{
    for (int i = 0; i < 10; ++i) {
        {
            std::lock_guard lock(io_m);
            std::cout << "tick\n";
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void t2()
{
    for (int i = 0; i < 5; ++i) {
        {
            std::lock_guard lock(io_m);
            std::cout << "tock\n";
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void t3()
{
    std::this_thread::sleep_for(std::chrono::seconds(10));
    {
        std::lock_guard lock(io_m);
        std::cout << "chime\n";
    }
}

int main(int argc, char const *argv[])
{
    std::thread thread1(t1);
    std::thread thread2(t2);
    std::thread thread3(t3);
    thread1.join();
    thread2.join();
    thread3.join();
    return 0;
}
