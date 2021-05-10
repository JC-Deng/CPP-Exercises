#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable c;
std::condition_variable c2;
int x = 0;
bool cnt = 0;
bool cnt2 = 0;

void t1()
{
    m.lock();
    x = 1;
    cnt = 1;
    c.notify_one();
    m.unlock();
}

void t2()
{
    std::unique_lock<std::mutex> lock(m);
    c.wait(lock, [](){return cnt;});
    int r2 = x; // 1 was assigned to r2.
    std::cout << r2 << '\n';
    cnt2 = 1;
    c2.notify_one();
}

void t3()
{
    std::unique_lock<std::mutex> lock(m);
    c2.wait(lock, [](){return cnt2;});
    int r3 = x; // 1 was assigned to r3.
    std::cout << r3 << '\n';
}

int main(int argc, char const *argv[])
{
    std::thread th1(t1);
    std::thread th2(t2);
    std::thread th3(t3);
    th1.join();
    th2.join();
    th3.join();
    return 0;
}
