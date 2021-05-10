#include<iostream>

class Counter
{
    private:
        int count;
        static int num_counters;
        
    public:
        Counter();
        Counter(int);
        ~Counter();
        Counter& operator++();
        int operator++(int);
        int GetValue() const;
        int NumberOfObjects() const;
};

int Counter::num_counters = 0;

Counter::Counter() : count(0)
{
    num_counters++;
}

Counter::~Counter()
{
    num_counters--;
}

Counter::Counter(int init) : count(init)
{
    num_counters++;
}

Counter& Counter::operator++()
{
    ++count;
    return *this;
}

int Counter::operator++(int)
{
    int temp = count++;
    return temp;
}

int Counter::GetValue() const
{
    return count;
}

int Counter::NumberOfObjects() const
{
    return num_counters;
}

int main(int argc, char const *argv[])
{
    Counter test_object_a;
    Counter test_object_b(10);
    Counter test_object_c(20);

    std::cout << test_object_a.NumberOfObjects() << '\n';
    std::cout << test_object_a++ << ' '
        << test_object_a.GetValue() << ' '
        << (++test_object_b).GetValue() << '\n';
    
    return 0;
}
