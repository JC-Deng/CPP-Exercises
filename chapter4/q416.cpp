template <class T, class U>
void func(const U& u)
{
   T x;
   // ...
}
int main()
{
   int x;
   func<int, int>(x);
   // Originally class T was never specified.
   // This way compiler now knows what's class T.
}
