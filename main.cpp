#include <iostream>

namespace mathOps
{
     int calculate(int x)
     {
          return x * x;
     }
}
namespace physicsOps
{
     int calculate(int y)
     {
          return y * 2;
     }
}f
int main()
{
     using namespace std;
     int input = 45;
     int out1 = mathOps::calculate(input);
     int out2 = physicsOps::calculate(input);
     cout << "mathOps sol:- " << out1 << endl;
     cout << "physicsOps sol:- " << out2 <<endl;
}