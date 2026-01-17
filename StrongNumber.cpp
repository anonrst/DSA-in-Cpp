#include <iostream>
#include <string.h>
int factorial(int num);
bool strongNumberDetector(int num);
int main()
{
     int num;
     std::cout << "what's N?  ";
     std::cin >> num;
     bool valv = strongNumberDetector(num);
     valv ? (std::cout << "Strong number" << std::endl) : (std::cout << "NOt Strong number" << std::endl);
}

bool strongNumberDetector(int num) {
  int original = num;
  int sum = 0;
  while(num > 0){
     int digit = num % 10;
     sum += factorial(digit);
     num /= 10; 
  }
  return original == sum;
}
int factorial(int num)
{
     int val = 1;
     for (int i = 1; i <= num; i++)
     {
          val *= i;
     }
     return val;
}