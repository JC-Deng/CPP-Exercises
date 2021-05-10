#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <atomic>

class AtomicCounter
{
    public:
        void main_thread()
        {
            std::vector<std::thread> ts;
            for (int i = 0; i < 4; ++i) {
                ts.emplace_back(std::thread(worker_thread));
            }
            for (auto& i : ts) {
                i.join();
            }
            std::cout << "Counter is now: " << counter << '\n';
        }
        static void worker_thread()
        {
            for (int i = 0; i < 20'000; ++i) {
                ++counter;
            }
        }
    
    private:
        static std::atomic<unsigned long long> counter;
};

std::atomic<unsigned long long> AtomicCounter::counter{0};

int main(int argc, char const *argv[])
{
    AtomicCounter ac;
    ac.main_thread();
    return 0;
}
