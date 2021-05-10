#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

class Outputer
{
    public:
        void t1() {
            std::lock_guard lock(m);
            std::cout << "Greetings!\n";
        }
        void t2() {
            {
                std::lock_guard lock(m);
                std::cout << "Sleep.\n";
            }
            std::this_thread::sleep_for(std::chrono::seconds(3));
            {
                std::lock_guard lock(m);
                std::cout << "Wakeup.\n";
            }
        }

    private:
        std::mutex m;
};

int main(int argc, char const *argv[])
{
    Outputer optr;
    std::thread thread_1(&Outputer::t1, std::ref(optr));
    std::thread thread_2(&Outputer::t2, std::ref(optr));
    thread_1.join();
    thread_2.join();
    return 0;
}
