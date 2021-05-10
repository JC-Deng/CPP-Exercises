#include "../chapter4/q408.cpp"
#include <boost/iterator/iterator_facade.hpp>
#include <iostream>
#include <memory>

template <class T>
class Stack<T>::Iterator : public boost::iterator_facade<
    Stack<T>::Iterator, Stack<T>, boost::forward_traversal_tag>
{
    private:
        Node *iter_ptr;
        Iterator(Node* const ptr) : iter_ptr(ptr) {}
        friend class Stack<T>::ConstIterator;
        friend const Stack<T>::Iterator Stack::begin();
        friend const Stack<T>::Iterator Stack::end();
    
    public:
        Iterator() : iter_ptr(NULL) {}
        Iterator(const Stack<T> &stk) : iter_ptr(stk.p) {}
        bool operator!=(const Stack<T>::Iterator &iter) const
        {
            return iter_ptr != iter.iter_ptr;
        }
        T& operator*()
        {
            return iter_ptr->data;
        }
        Node* operator++()
        {
            return (iter_ptr = iter_ptr->next);
        }
        bool equal(const Iterator in_iter) const
        {
            return iter_ptr == in_iter.iter_ptr;
        }
};

int main(int argc, char const *argv[])
{
    Stack<int> test_stack;
    for (int i = 0; i < 10; i++) {
        test_stack.push(i);
    }

    Stack<int>::Iterator si = test_stack.begin();
    for (Stack<int>::Iterator i = test_stack.begin();
        i != test_stack.end(); ++i) {
        ++(*i);
        std::cout << *i << ' ';
    }
    std::cout << '\n';

    auto test_smart_ptr(std::make_unique<Stack<int>>());

    return 0;
}
