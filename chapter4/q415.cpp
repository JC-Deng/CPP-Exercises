#include <iostream>
#include <stack>

template <typename T>
void arg_2_stk(std::stack<char> &stk, T c)
{
    stk.push(c);
}

template <typename T, typename... Ts>
void arg_2_stk(std::stack<char> &stk, T first, Ts... Args)
{
    arg_2_stk(stk, Args...);
    stk.push(first);
}

template <char... Args>
int operator""_4()
{
    std::stack<char> stk;
    arg_2_stk(stk, Args...);
    int res = 0;
    while (!stk.empty()) {
        if (stk.top() == '-') {
            res *= -1;
        } else {
            res = res*4 + stk.top() - 48;
        }
        stk.pop();
    }
    return res;
}

int main()
{
   // Output 1 4 16
   std::cout << 1_4 << " " << 10_4 << " " << 100_4 << "\n";
   // Output -1 -4 -16
   std::cout << -1_4 << " " << -10_4 << " " << -100_4 << "\n";
   // Output 228 27
   std::cout << 3210_4 << " " << 0123_4 << "\n";
   // Output -228 -27
   std::cout << -3210_4 << " " << -0123_4 << "\n";
}
