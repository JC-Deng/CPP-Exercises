#include<iostream>

class IntArray2
{
    private:
        int **int_arr_2;
        // I can't find good ways to determine the size
        // of newed space, so I stored the values as
        // data members.
        int num_row;
        int num_col;
    
    public:
        IntArray2();
        IntArray2(int, int);
        IntArray2(const IntArray2&);
        IntArray2(IntArray2&&);
        ~IntArray2();

        int Height() const;
        int Width() const;
        int Size() const;
        int& operator()(int, int);

        friend std::ostream& operator<<(std::ostream&,
            const IntArray2&);
        friend std::istream& operator>>(std::istream&,
            IntArray2&);
};

IntArray2::IntArray2() : int_arr_2(nullptr), num_row(0),
    num_col(0) {}

IntArray2::IntArray2(int rows, int col)
    : int_arr_2(new int*[rows]), num_row(rows), num_col(col)
{
    for (int i = 0; i < num_row; i++) {
        int_arr_2[i] = new int[col]();
    }
}

IntArray2::IntArray2(const IntArray2 &copy_obj) 
    : int_arr_2(new int*[copy_obj.num_row]),
    num_row(copy_obj.num_row), num_col(copy_obj.num_col)
{
    for (int i = 0; i < num_row; i++) {
        int_arr_2[i] = new int[copy_obj.num_col];
        for (int j = 0; j < num_col; j++) {
            int_arr_2[i][j] = copy_obj.int_arr_2[i][j];
        }
    }
}

IntArray2::IntArray2(IntArray2 &&move_obj)
    : int_arr_2(std::move(move_obj.int_arr_2)),
    num_row(move_obj.num_row), num_col(move_obj.num_col) {}

IntArray2::~IntArray2()
{
    if (!this->int_arr_2) {
        for (int i = 0; i < num_row; i++) {
            delete[] int_arr_2[i];
        }
        delete[] int_arr_2;
    }
}

int IntArray2::Height() const
{
    return num_row;
}

int IntArray2::Width() const
{
    return num_col;
}

int IntArray2::Size() const
{
    return num_row*num_col;
}

int& IntArray2::operator()(int row, int col)
{
    int &element_ref = int_arr_2[row][col];
    return element_ref;
}

std::ostream& operator<<(std::ostream &os,
    const IntArray2 &out_obj)
{
    for (int i = 0; i < out_obj.num_row; i++) {
        for (int j = 0; j < out_obj.num_col; j++) {
            std::cout << out_obj.int_arr_2[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return os;
}

std::istream& operator>>(std::istream &is,
    IntArray2 &in_obj)
{
    int counter = 0;
    int up_limit = in_obj.Size();
    for (int i = 0; i < in_obj.Height(); i++) {
        for (int j = 0; j < in_obj.Width(); j++) {
            if (!(std::cin >> in_obj.int_arr_2[i][j])) {
                return is;
            }
            if (++counter >= up_limit) {
                return is;
            }
        }
    }
    return is;
}

int main(int argc, char const *argv[])
{
    IntArray2 void_array;
    std::cout << "Size of empty array: " << '\n'
        << void_array.Size() << "\n\n";
    
    IntArray2 test_array(2, 3);
    std::cin >> test_array;
    std::cout << test_array << '\n';

    IntArray2 copy_array(test_array);
    std::cout << test_array << copy_array << '\n';
    
    IntArray2 move_array(std::move(test_array));
    std::cout << move_array << '\n';

    std::cout << move_array.Height() << '\n'
        << move_array.Width() << '\n'
        << move_array.Size() << "\n\n";

    move_array(0, 2) = 9999;
    std::cout << move_array << "\n\n";

    return 0;
}
