#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>

bool ready = false;
std::mutex m;
std::condition_variable c;

void DoWork(int id)
{
    std::unique_lock<std::mutex> lock(m);
    c.wait(lock, [](){return ready;});
    std::cout << id << '\n';
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> ts;
    for (int i = 0; i < 10; ++i) {
        ts.emplace_back(DoWork, i);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    ready = true;
    c.notify_all();
    for (auto& i : ts) {
        i.join();
    }
    return 0;
}
