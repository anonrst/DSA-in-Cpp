#include <iostream>

int factorial(int num);
int fibonacci(int n);  

int main(void)
{
     int value = factorial(6);
     std::cout << "Factorial of 6: " << value << std::endl;
     
     std::cout << "\nFibonacci sequence (first 10):\n";
     for (int i = 0; i < 10; i++)
     {
          std::cout << fibonacci(i) << " ";
     }
     std::cout << std::endl;
     
     return 0;
}

int factorial(int num)
{
     if (num > 1)
     {
          return num * factorial(num - 1);
     }
     else
     {
          return 1;
     }
}

int fibonacci(int n)
{
     if (n <= 1)
     {
          return n;
     }
     return fibonacci(n - 1) + fibonacci(n - 2);
}