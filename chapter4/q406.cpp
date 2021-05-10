#include <iostream>

template <class T> class Vector {
    private:
        T* p_vec;
        int size_vec;
        
    public:
        Vector() : p_vec(nullptr), size_vec(0) {};
        Vector(int size) : p_vec(new T[size]()), size_vec(size) {};
        ~Vector() {
            if (size_vec) {
                delete[] p_vec;
                p_vec = nullptr;
            }
        }
        T& operator[](int num) {
            return p_vec[num];
        }
        template <class TF> friend std::ostream& operator<< (std::ostream& os, const Vector<TF> &out_obj) {
            for (int i = 0; i < out_obj.size_vec; i++)  {
                std::cout << out_obj.p_vec[i];
            }
            return os;
        }
};

int main(int argc, char const *argv[])
{
    Vector<int> test_vec();
    Vector<int> test_vec_2(1);
    Vector<int> test_vec_3(5);
    test_vec_3[2] = 3;
    std::cout << test_vec_3 << '\n';
    
    return 0;
}
