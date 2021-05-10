#include<iostream>
#include<vector>

class IntStack
{
    private:
        int *stack_begin;
        int *stack_top;
        int stack_size;
        int top_location;
    
    public:
        IntStack();
        IntStack(int);
        ~IntStack();
        int Push(int);
        int Pop();
        int Get() const;
        int Size() const;
};

IntStack::IntStack()
    : stack_begin(new int[3]), stack_size(3), top_location(0)
{
    stack_top = stack_begin;
}

IntStack::IntStack(int usr_size)
    : stack_begin(new int[usr_size]), stack_size(usr_size),
    top_location(0)
{
    stack_top = stack_begin;
}

IntStack::~IntStack()
{
    if (!stack_begin) {
        delete[] stack_begin;
    }
    stack_top = nullptr;
}

int IntStack::Push(int dat)
{
    if (top_location < stack_size) {
        *stack_top = dat;
        top_location++;
        stack_top++;
        return dat;
    } else {
        throw std::overflow_error("Stack full.");
    }
}

int IntStack::Pop()
{
    if (top_location != 0) {
        top_location--;
        stack_top--;
        return *stack_top;
    } else {
        throw std::overflow_error("Stack empty.");
    }
}

int IntStack::Get() const
{
    if (top_location != 0) {
        int *temp = stack_top;
        return *(--temp);
    } else {
        throw std::overflow_error("Stack empty.");
    }
}

int IntStack::Size() const
{
    return top_location;
}

int main(int argc, char const *argv[])
{
    IntStack test_stack;
    std::cout << test_stack.Push(0) << test_stack.Size()
        << test_stack.Push(0) << test_stack.Size()
        << test_stack.Pop() << test_stack.Size()
        << test_stack.Pop() << test_stack.Size() << '\n';
    try {
        test_stack.Push(1);
        test_stack.Push(2);
        test_stack.Push(3);
        test_stack.Push(4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << test_stack.Get() << '\n';
    try
    {
        test_stack.Pop();
        test_stack.Pop();
        test_stack.Pop();
        test_stack.Pop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
