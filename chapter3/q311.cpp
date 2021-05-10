#include<iostream>

class Base
{
    public:
        virtual void display();
};

void Base::display()
{
    std::cout << "Base\n";
}

class Derived1 : public Base
{
    public:
        void display();
};

void Derived1::display()
{
    std::cout << "Derived1\n";
}

class Derived2 : public Base
{
    public:
        void display();
};

void Derived2::display()
{
    std::cout << "Derived2\n";
}

int main(int argc, char const *argv[])
{
    Base base_obj;
    Derived1 d1_obj;
    Derived2 d2_obj;

    base_obj.display();
    d1_obj.display();
    d2_obj.display();
    
    Base *base_ptr = new Base();
    Base *d1_ptr = new Derived1();
    Base *d2_ptr = new Derived2();

    base_ptr->display();
    d1_ptr->display();
    d2_ptr->display();
    
    return 0;
}
