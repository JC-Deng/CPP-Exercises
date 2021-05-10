#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::move;
using std::to_string;

class Histogram
{
    private:
        map<double, int> histo_data;

    public:
        Histogram() = delete;
        Histogram(vector<double>);
        Histogram(Histogram&);
        Histogram(Histogram&&);
        Histogram& operator=(Histogram&);
        Histogram& operator=(Histogram&&);
        ~Histogram();
        void Clear();
        void Update(double);
        void Display();
};

Histogram::Histogram(vector<double> bonds_vector)
{
    for (vector<double>::iterator i = bonds_vector.begin();
        i != bonds_vector.end(); i++)
    {
        Histogram::histo_data[*i] = 0;
    }
}

Histogram::Histogram(Histogram &copy_object) 
    : histo_data(copy_object.histo_data) {}

Histogram::Histogram(Histogram &&move_object)
    : histo_data(move(move_object.histo_data)) {}

Histogram& Histogram::operator=(Histogram &copy_object)
{
    this -> histo_data = copy_object.histo_data;
    return *this;
}

Histogram& Histogram::operator=(Histogram &&move_object)
{
    this -> histo_data = move(move_object.histo_data);
    return *this;
}

Histogram::~Histogram() {}

void Histogram::Clear()
{
    for (map<double, int>::iterator i = histo_data.begin();
        i != histo_data.end(); i++)
    {
        i->second = 0;
    }
}

void Histogram::Update(double data)
{
    map<double, int>::iterator i = histo_data.begin();
    if (data < i -> first)
    {
        throw std::invalid_argument
            ("Invalid input: Smaller than minimum.");
    }

    while (i != histo_data.end())
    {
        if (data < i -> first)
        {
            i -> second++;
            return;
        }
        i++;
    }

    if (data == (--i) -> first)
    {
        i -> second++;
        return;
    }

    throw std::invalid_argument
        ("Invalid input: Larger than Maximum.");
}

void Histogram::Display()
{
    if (histo_data.empty())
    {
        cout << "Empty histogram." << endl;
        return;
    }

    cout.setf(std::ios::left);
    map<double, int>::iterator i = ++histo_data.begin();
    do
    {
        i--;
        cout.width(6);
        cout << i -> first << " - ";
        i++;
        cout.width(8);
        cout << i -> first << ": ";
        for (int m = 0; m < i -> second; m++)
        {
            cout << '*';
        }
        cout << '\n';
        i++;
    } while (i != histo_data.end());
}

int main(int argc, char const *argv[])
{
    vector<double> bonds = {1, 2, 3, 4};
    Histogram origin_object(bonds);

    try
    {
        origin_object.Update(1);
        origin_object.Update(1.2);
        origin_object.Update(1.3);
        origin_object.Update(1.3);
        origin_object.Update(2);
        origin_object.Update(2.9);
        origin_object.Update(3);
        origin_object.Update(3.5);
        origin_object.Update(4);
        origin_object.Update(4.1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    origin_object.Display();

    Histogram copy_object(origin_object);
    
    cout << endl;
    origin_object.Clear();
    origin_object.Display();

    cout << endl;
    Histogram move_object(move(copy_object));
    move_object.Display();
    copy_object.Display();

    cout << endl;
    Histogram copy_opr_object = move_object;
    copy_opr_object.Display();
    move_object.Display();
    
    cout << endl;
    Histogram move_opr_object = move(move_object);
    move_opr_object.Display();
    move_object.Display();

    return 0;
}
