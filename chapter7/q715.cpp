#include <iostream>
#include <thread>
// Replace the following line with the appropriate
// header file for your scoped_thread class.
// #include "scoped_thread.hpp"

class scoped_thread
{
    private:
        std::thread RAIIed_thread;

    public:
        scoped_thread() = delete;
        scoped_thread(std::thread&& in_thread)
            : RAIIed_thread(std::move(in_thread)) {}
        ~scoped_thread()
        {
            if (RAIIed_thread.joinable()) {
                RAIIed_thread.join();
            }
        }
};

void bonjour()
{
    std::cout << "Bonjour, Le Monde!\n";
}

int main()
{
    // Include extra set of parentheses on the following
    // line in order to avoid the most-vexing parse problem.
    scoped_thread t1((std::thread(bonjour)));
    scoped_thread t2(std::thread([](){
        std::cout << "Hello, World!\n";
    }));
}
