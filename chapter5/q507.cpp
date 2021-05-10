/*
For iterator method, stepping through GNU C++ library looks like this:


13	    sum += *i;
__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator* (this=0x7ffffffedbd0)
    at /usr/include/c++/9/bits/stl_iterator.h:819
819	      operator*() const _GLIBCXX_NOEXCEPT
820	      { return *_M_current; }
calcSum1 (v=std::vector of length 3, capacity 3 = {...}) at /mnt/d/Project/jcdeng-programming-exercises/chapter5/tst.cpp:12
12	    for (auto i = v.begin(); i != v.end(); ++i) {
__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator++ (this=0x7ffffffedb70)
    at /usr/include/c++/9/bits/stl_iterator.h:827
827	      operator++() _GLIBCXX_NOEXCEPT
829		++_M_current;
830		return *this;
831	      }
std::vector<int, std::allocator<int> >::end (this=0x7ffffffedc60) at /usr/include/c++/9/bits/stl_vector.h:835
835	      end() const _GLIBCXX_NOEXCEPT
836	      { return const_iterator(this->_M_impl._M_finish); }
__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::__normal_iterator (this=0x7ffffffedab0, 
    __i=@0x7ffffffeda90: 0x60200000001c) at /usr/include/c++/9/bits/stl_iterator.h:806
806	      __normal_iterator(const _Iterator& __i) _GLIBCXX_NOEXCEPT
807	      : _M_current(__i) { }
std::vector<int, std::allocator<int> >::end (this=0x7ffffffedc60) at /usr/include/c++/9/bits/stl_vector.h:835
835	      end() const _GLIBCXX_NOEXCEPT
836	      { return const_iterator(this->_M_impl._M_finish); }
__gnu_cxx::operator!=<int const*, std::vector<int, std::allocator<int> > > (__lhs=non-dereferenceable iterator for std::vector, __rhs=-74512)
    at /usr/include/c++/9/bits/stl_iterator.h:907
907	    operator!=(const __normal_iterator<_Iterator, _Container>& __lhs,
910	    { return __lhs.base() != __rhs.base(); }
__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::base (this=0x1fafa73899c9600)
    at /usr/include/c++/9/bits/stl_iterator.h:871
871	      base() const _GLIBCXX_NOEXCEPT
872	      { return _M_current; }
__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::base (this=0x7ffffffedb70)
    at /usr/include/c++/9/bits/stl_iterator.h:871
871	      base() const _GLIBCXX_NOEXCEPT
872	      { return _M_current; }
calcSum1 (v=std::vector of length 3, capacity 3 = {...}) at /mnt/d/Project/jcdeng-programming-exercises/chapter5/tst.cpp:13
13	    sum += *i;


For the second method, stepping through it is like this:


22	        sum += v[i];
std::vector<int, std::allocator<int> >::operator[] (this=0x7ffffffedc60, __n=0) at /usr/include/c++/9/bits/stl_vector.h:1058
1058	      operator[](size_type __n) const _GLIBCXX_NOEXCEPT
1061		return *(this->_M_impl._M_start + __n);
1062	      }
calcSum2 (v=std::vector of length 3, capacity 3 = {...}) at /mnt/d/Project/jcdeng-programming-exercises/chapter5/tst.cpp:21
21	    for (int i = 0; i < v.size(); ++i) {
std::vector<int, std::allocator<int> >::size (this=0x7ffffffedc60) at /usr/include/c++/9/bits/stl_vector.h:915
915	      size() const _GLIBCXX_NOEXCEPT
916	      { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
calcSum2 (v=std::vector of length 3, capacity 3 = {...}) at /mnt/d/Project/jcdeng-programming-exercises/chapter5/tst.cpp:22
22	        sum += v[i];


One loop in the first method involves dereference -> iterate forward -> get end()
-> compare with end() -> return current value.
However, using [] will simply offset the pointer to the head of a vector and get
its value, which is the quickest way I think there is to visit a sequentially
stored container.
*/

#include <vector>
#include <iostream>
#include <chrono>

int calcSum1(const std::vector<int>& v)
{
    int sum = 0;
    for (auto i = v.begin(); i != v.end(); ++i) {
    sum += *i;
    }
    return sum;
}

int calcSum2(const std::vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    std::vector<int> test_vec(16777216, 3);
    auto time_1 = std::chrono::high_resolution_clock::now();
    std::cout << calcSum1(test_vec) << '\n';
    auto time_2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<
        std::chrono::duration<double>>(time_2 - time_1).count() << '\n';
    std::cout << calcSum2(test_vec) << '\n';
    auto time_3 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<
        std::chrono::duration<double>>(time_3 - time_2).count() << '\n';

    return 0;
}
