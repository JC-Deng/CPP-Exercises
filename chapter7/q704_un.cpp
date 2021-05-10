#include <list>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>

class IntQueue
{
    private:
        std::list<int> int_lst;
        mutable std::mutex rw_lock;
        mutable std::condition_variable c_v;
    
    public:
        int get() {
            std::unique_lock<std::mutex> lock(rw_lock);
            c_v.wait(lock, [this](){return !int_lst.empty();});
            int res = int_lst.front();
            int_lst.pop_front();
            return res;
        }
        void put(int opn) {
            std::lock_guard<std::mutex> lock(rw_lock);
            int_lst.push_back(opn);
            c_v.notify_one();
        }
};

int main(int argc, char const *argv[])
{
    IntQueue iq;
    std::thread producer([&](){
        for (int i = 0; i < 1000; ++i) {
            iq.put(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        iq.put(-1);
        std::cout << "Producer complete.\n";
    });
    std::thread consumer([&](){
        int x = iq.get();
        while (x >= 0) {
            std::cout << x << '\n';
            x = iq.get();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        std::cout << x;
    });
    producer.join();
    consumer.join();
    return 0;
}