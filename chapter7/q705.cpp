#include <thread>
#include <chrono>
#include <iostream>
#include <boost/thread/scoped_thread.hpp>

void doWork(){}
void doStuff()
{
    throw "Somthing.";
}

// In the following code, doStuff() might throw, and
// thread t might never have a chance join. This will
// cause the termination of this program.
void runThread()
{
    std::thread t(doWork);
    doStuff();
    t.join();
}

// To address this issue, the first solution is to write
// join() in a try catch block.
void runThread2()
{
    std::thread t(doWork);
    try {
        doStuff();
        t.join();
    } catch(char const* e) {
        std::cout << e << '\n';
        t.join();
    }
}

// Or, we can use RAII approach on threads to ensure join().
class thread_guard
{
    std::thread& t;
    public:
    explicit thread_guard(std::thread& t_): t(t_){}
    ~thread_guard()
    {
        if(t.joinable())
    {
        t.join();
    }
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;
};

void runThread3()
{
    std::thread t(doWork);
    thread_guard g(t);
    doStuff();
}

int main(int argc, char const *argv[])
{
    try {
        runThread2();
    } catch(char const* e) {
        std::cout << e << '\n';
    }
    return 0;
}
