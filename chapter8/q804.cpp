#include <iostream>
#include <memory>

class SharedInt
{
  public:
    // default constructor
    SharedInt(int i = 0) : p_(std::make_shared<int>(i)) {}

    // copy constructor
    SharedInt(SharedInt& i) : p_(i.p_) {}

    // move constructor
    SharedInt(SharedInt&& i) : p_(std::move(i.p_)) {}

    // copy assignment operator
    SharedInt& operator=(const SharedInt& i)
    {
      if (this != &i) {
        p_ = i.p_;
      }
      return *this;
    }

    // move assignment operator
    SharedInt& operator=(SharedInt&& i)
    {
      p_ = std::move(i.p_);
      return *this;
    }

    // get the underlying integer value
    int get() const
    {
      return *p_;
    }

    // compute the square
    SharedInt square() const
    {
      return SharedInt((*p_) * (*p_));
    }

    // increment
    SharedInt& operator++()
    {
      ++(*p_);
      return *this;
    }

  private:
    // shared pointer to integer
    std::shared_ptr<int> p_;
};

int main()
{
  SharedInt x(2); // Default construction.
  SharedInt y(x.square()); // Default construnction.
  SharedInt z(x); // Copy construction.
  SharedInt w(std::move(y)); // Move construction.
  y = std::move(w); // Move assignment.
  w = y.square(); // Default constructed temporary object then moved to w.
  x = y; // Copy assignment.
  ++z;
  std::cout << w.get() << " " << x.get() << " " << y.get() << " " <<
    z.get() << "\n";
}
