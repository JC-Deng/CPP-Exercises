#include <atomic>
#include <vector>
#include <thread>
#include <iostream>
#include <chrono>
#include <random>
#include <mutex>

std::mutex io_m;
std::atomic_long global_max_value(std::numeric_limits<long>::min());

long get_random()
{
    thread_local static std::default_random_engine
        gen((std::random_device()()));
    thread_local static std::uniform_int_distribution<long>
        dist(0, 999'999l);
    return dist(gen);
}

void worker(int id)
{
    thread_local long r;
    thread_local long local_max_r;
    for (int i = 0; i < 10'000; ++i) {
        r = get_random();
        if (r > local_max_r) {
            local_max_r = r;
        }
    }
    if (local_max_r > global_max_value) {
        global_max_value = local_max_r;
    }
    {
        std::lock_guard<std::mutex> lock(io_m);
        std::cout << "Thread " << id << ": " << local_max_r << '\n';
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> worker_threads;
    for (int i = 0; i < 4; ++i) {
        worker_threads.emplace_back(worker, i);
    }
    for (auto& i : worker_threads) {
        i.join();
    }
    std::cout << "All: " << global_max_value << '\n';
    return 0;
}
