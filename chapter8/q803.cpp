#include <utility>
#include <string>

void func(std::string&) {}; // func 1.
void func(const std::string&) {}; // func 2.
void func(std::string&&) {}; // func 3.
void func(const std::string&&) {}; // func 4.

const std::string getConstString()
{
	return std::string("Bjarne");
}

int main()
{
	const std::string cs{"Hello"};
	std::string s = cs;
	func(cs); // func 2.
	func(s); // func 1.
	func(s + "!"); // func 3.
	func(s + s); // func 3.
	func(std::move(s)); // func 3.
	func(getConstString()); // func 4.
}
