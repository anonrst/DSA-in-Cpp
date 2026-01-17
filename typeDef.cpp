#include <iostream>

typedef unsigned long long ull;
ull square(ull x);
int main()
{
     ull val = square(12);
     std::cout << "Result: " << val << std::endl;
};

ull square(ull x)
{
     return x*x;
}