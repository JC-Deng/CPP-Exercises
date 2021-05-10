#include <iostream>
#include <cassert>
#include <memory>

class Counter
{
    public:
        Counter(int i = 0) : p_(new int(i)) {}
        ~Counter() {
            if (p_) {
                delete p_;
                std::cout << "Destructor called." << '\n';
            }
        }
        Counter(Counter&& c) : p_(c.p_) {
            c.p_ = nullptr;
        }
        Counter(const Counter& c) {
            if (p_) {
                p_ = new int(*c.p_);
            } else {
                p_ = nullptr;
            }
        }
    Counter& operator=(Counter&& c) {
        if (this != &c) {
            if (p_) {
                delete p_;
            }
            p_ = c.p_;
            c.p_ = nullptr;
        }
        return *this;
    }
    Counter& operator=(const Counter& c) {
        if (this != &c) {
            if (p_) {
                delete p_;
            }
            p_ = new int(*c.p_);
        }
        return *this;
    }
    int getCount() const {
        assert(p_);
        return *p_;
    }
    Counter& operator++() {
        assert(p_);
        ++*p_;
        return *this;
    }

    private:
        int* p_; // pointer to counter value
};

int main() {
    auto a_fix = std::make_shared<Counter>(0);
    auto b_fix(std::move(a_fix));
    auto c_fix(b_fix);
    c_fix = std::move(b_fix);
    b_fix = std::make_unique<Counter>(++(*c_fix));
    a_fix = std::make_unique<Counter>(++(*c_fix));
    std::cout << a_fix->getCount() << '\n'
        << b_fix->getCount() << '\n'
        << c_fix->getCount() << '\n';
}