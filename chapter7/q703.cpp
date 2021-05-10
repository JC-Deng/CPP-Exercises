#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>


// void thread_exhibit()
// {
//     static std::mutex io_mutex;
//     std::scoped_lock lock(io_mutex);
//     std::cout << 
// }

class ThreadExhibiter
{
    public:
        std::mutex io_mutex;
        void exhibit()
        {
            std::scoped_lock lock(io_mutex);
            std::cout << "Greetings from thread " << std::this_thread::get_id() << '\n';
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
};

int main(int argc, char const *argv[])
{
    ThreadExhibiter te;
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(&ThreadExhibiter::exhibit, std::ref(te));
    }
    for (auto& i : threads) {
        i.join();
    }
    return 0;
}

