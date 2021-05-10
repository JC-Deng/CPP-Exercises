#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;

std::ostream&
OutputOne(std::ostream& os)
{
    return os;
}

template <class A0, class ...Args>
std::ostream&
OutputOne(std::ostream& os, const A0& a0, const Args& ...args)
{
    os << a0;
    return OutputOne(os, args...);
}

template <class ...Args>
std::ostream&
Output(std::ostream& os, const Args& ...args)
{
    return OutputOne(os, args...);
}

template <class ...Args>
std::ostream&
Output(const Args& ...args)
{
    std::lock_guard<std::mutex> lock(mtx);
    return Output(std::cout, args...);
}

void Execution()
{
    Output(std::cout, "This is thread no ", std::this_thread::get_id(), '\n');
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> thread_vec;
    for (int i = 0; i < 8; ++i) {
        thread_vec.emplace_back(Execution);
    }
    for (auto& i : thread_vec) {
        i.join();
    }
    return 0;
}
