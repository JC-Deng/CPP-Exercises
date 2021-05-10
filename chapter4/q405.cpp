#include<iostream>
#include<utility>

template <class T, int container_size> class Array
{
    private:
        T arr[container_size] = {0};

    public:
        Array() {}
        Array(std::initializer_list<T> list) {
            T *tmp = arr;
            for (typename std::initializer_list<T>::iterator iter = list.begin();
                iter != list.end(); iter++) {
                *tmp = *iter;
                tmp++;
            }
        }
        Array(const Array<T, container_size> &copy_obj) {
            std::copy(std::begin(copy_obj.arr), std::end(copy_obj.arr), std::begin(arr));
        }
        Array(Array<T, container_size> &&move_obj) {
            for (int i = 0; i < container_size; i++) {
                arr[i] = std::move(move_obj.arr[i]);
            }
        }
        T& operator[](int num) {
            return arr[num];
        }
        constexpr int size() {
            return container_size;
        }
        void fill(T num) {
            for (int i = 0; i < container_size; i++) {
                arr[i] = num;
            }
        }
        template <class TF, int io_size>
            friend std::ostream& operator<<(std::ostream&,
            Array<TF, io_size>&);
};

template <class TF, int io_size>
std::ostream& operator<<(std::ostream &os,
    Array<TF, io_size> &out_obj)
{
    for (int i = 0; i < io_size; i++) {
        std::cout << out_obj.arr[i];
    }
    return os;
}

// int main(int argc, char const *argv[])
// {
//     Array<int, 8> test_arr;
//     Array<int, 8> test_arr_init({1, 2, 3});
//     Array<int, 8> copy_arr(std::move(test_arr_init));
//     std::cout << copy_arr << '\n';
//     std::cout << test_arr_init << '\n';

//     return 0;
// }

int main()
{
    const Array<int, 4> a{1, 2, 3, 4};
    const Array<int, 4> b{1, 2};
    auto c = a;
    auto d = b;
    auto e(std::move(c));
    std::cout << c << "\n";
}
