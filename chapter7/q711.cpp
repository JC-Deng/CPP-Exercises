#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <chrono>

class ReaderAndWriter
{
    public:
        void writer() {
            for (int v = 0; v <= 3; ++v) {
                std::unique_lock rw_l(rw_m);
                value = v;
                std::lock_guard io_l(io_m);
                std::cout << "Writer: " << v << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
        void reader(int id) const {
            for (int v = 0; v < 20; ++v) {
                std::shared_lock rw_l(rw_m);
                std::lock_guard io_l(io_m);
                std::cout << "Reader " << id << ": " << value << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }
        }
        
    private:
        int value;
        mutable std::shared_mutex rw_m;
        mutable std::mutex io_m;
};

int main(int argc, char const *argv[])
{
    std::vector<std::thread> ts;
    ReaderAndWriter rw;
    auto write = [&rw](){rw.writer();};
    auto read = [&rw](int id){rw.reader(id);};
    ts.emplace_back(write);
    for (int i = 0; i < 3; ++i) {
        ts.emplace_back(read, i);
    }
    for (auto& i : ts) {
        i.join();
    }
    return 0;
}
