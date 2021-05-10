#include <iostream>
#include <boost/iterator/iterator_facade.hpp>

template <class T> class Vector {
    private:
        T* p_vec;
        int size_vec;
        
    public:
        class Iterator;
        friend class Iterator;
        class ConstIterator;
        const Iterator begin();
        const Iterator end();
        Vector() : p_vec(nullptr), size_vec(0) {};
        Vector(int size) : p_vec(new T[size]()), size_vec(size) {};
        ~Vector() {
            if (size_vec) {
                delete[] p_vec;
                p_vec = nullptr;
            }
        }
        T& operator[](int num) {
            if (num >= size_vec) {
                abort();
            }
            return p_vec[num];
        }
        template <class TF> friend std::ostream& operator<< (std::ostream& os, const Vector<TF> &out_obj) {
            for (int i = 0; i < out_obj.size_vec; i++)  {
                std::cout << out_obj.p_vec[i];
            }
            return os;
        }
};

template <class T>
const typename Vector<T>::Iterator Vector<T>::begin()
{
    return Iterator(this->p_vec);
}

template <class T>
const typename Vector<T>::Iterator Vector<T>::end()
{
    return Iterator(this->p_vec + this->size_vec);
}

template <class T>
class Vector<T>::Iterator : public boost::iterator_facade<
    Vector<T>::Iterator, Vector<T>, boost::forward_traversal_tag>
{
    private:
        T *iter_ptr;
        Iterator(T* const ptr) : iter_ptr(ptr) {}
        friend class Vector<T>::ConstIterator;
        friend const Vector<T>::Iterator Vector::begin();
        friend const Vector<T>::Iterator Vector::end();
    
    public:
        Iterator() : iter_ptr(nullptr) {}
        Iterator(const Vector<T> &vec) : iter_ptr(vec.p_vec) {}
        bool operator!=(const Vector<T>::Iterator &iter) const
        {
            return iter_ptr != iter.iter_ptr;
        }
        T& operator*()
        {
            return *iter_ptr;
        }
        T* operator++(int)
        {
            return iter_ptr++;
        }
        T* operator++()
        {
            return ++iter_ptr;
        }
        bool equal(const Iterator in_iter) const
        {
            return iter_ptr == in_iter.iter_ptr;
        }
};

template <class T>
class Vector<T>::ConstIterator : public boost::iterator_facade<
    Vector<T>::ConstIterator, Vector<T>, boost::forward_traversal_tag>
{
    private:
        T const *const_iter_ptr;
        friend class Vector<T>::Iterator;
    
    public:
        friend class Vector<T>::Iterator;
        ConstIterator() : const_iter_ptr(nullptr) {}
        ConstIterator(const Iterator &iter) : const_iter_ptr(iter.iter_ptr) {}
        ConstIterator(const Vector<T> &vec) : const_iter_ptr(vec.p_vec) {}
        bool operator!=(const Vector<T>::Iterator &iter) const
        {
            return const_iter_ptr != iter.iter_ptr;
        }
        T const& operator*()
        {
            return *const_iter_ptr;
        }
        T const* operator++(int)
        {
            return const_iter_ptr++;
        }
        T const* operator++()
        {
            return ++const_iter_ptr;
        }
        bool equal(const ConstIterator in_iter) const
        {
            return const_iter_ptr == in_iter.const_iter_ptr;
        }
};

int main(int argc, char const *argv[])
{
    Vector<int> test_vec();
    Vector<int> test_vec_2(1);
    Vector<int> test_vec_3(5);
    test_vec_3[4] = 3;
    std::cout << test_vec_3 << '\n';
    
    Vector<int>::Iterator vi = test_vec_3.begin();
    for (Vector<int>::Iterator i = test_vec_3.begin();
        i != test_vec_3.end(); ++i) {
        ++(*i);
    }
    Vector<int>::ConstIterator vci = vi;
    for (Vector<int>::ConstIterator i = test_vec_3.begin();
        i != test_vec_3.end(); ++i) {
        std::cout << *i;
    }
    std::cout << "\n";
    return 0;
}
