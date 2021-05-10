#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <vector>

std::mutex m_a;
std::condition_variable c_a;
int data_a = 0;
bool ready_a = 0;

void producer_a()
{
    std::lock_guard<std::mutex> lock(m_a);
    data_a = 1;
    ready_a = 1;
    c_a.notify_one();
}

void consumer_a()
{
    std::unique_lock<std::mutex> lock(m_a);
    c_a.wait(lock, [](){return ready_a;});
    std::cout << data_a << '\n';
}

std::mutex m_b;
std::condition_variable c_b_1;
std::condition_variable c_b_2;
int data_b = 0;
bool produced_b = 0;
bool consumed_b = 0;
int counter = 0;

void producer_b()
{
    std::unique_lock<std::mutex> lock(m_b);
    c_b_2.wait(lock,[](){return consumed_b;});
    for (int i = 0; i < 9999; ++i) {
        data_b = i;
        consumed_b = 0;
        produced_b = 1;
        c_b_1.notify_one();
        c_b_2.wait(lock, [](){return consumed_b;});
    }
    data_b = 9999;
    consumed_b = 0;
    produced_b = 1;
    c_b_1.notify_one();
}

void consumer_b()
{
    std::unique_lock<std::mutex> lock(m_b);
    consumed_b = 1;
    c_b_2.notify_one();
    c_b_1.wait(lock, [](){return produced_b;});
    for (int i = 0; i < 9999; ++i) {
        std::cout << data_b << '\n';
        consumed_b = 1;
        produced_b = 0;
        c_b_2.notify_one();
        c_b_1.wait(lock, [](){return produced_b;});
    }
    std::cout << data_b << '\n';
    consumed_b = 1;
    produced_b = 0;
    c_b_2.notify_one();
}

int main(int argc, char const *argv[])
{
    // std::thread t_producer(producer_a);
    // std::thread t_consumer(consumer_a);
    // t_producer.join();
    // t_consumer.join();

    // std::thread t_producer_b(producer_b);
    // std::thread t_consumer_b(consumer_b);
    // t_producer_b.join();
    // t_consumer_b.join();

    std::vector<std::thread> vec_producer;
    std::vector<std::thread> vec_consumer;
    for (int i = 0; i < 4; ++i) {
        vec_producer.emplace_back(producer_b);
        vec_producer.emplace_back(consumer_b);
    }
    for (auto& i : vec_producer) {
        i.join();
    }
    for (auto& i : vec_consumer) {
        i.join();
    }

    return 0;
}
