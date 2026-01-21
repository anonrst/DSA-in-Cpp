#include <iostream>
bool isPrime(int num);

int main()
{
     int numInput;
     std::cout << "Enter a number: ";
     std::cin >> numInput;
     
     if (numInput < 2)
     {
          std::cout << numInput << " is not prime\n";
          return 0;
     }
     
     bool result = isPrime(numInput);
     std::cout << numInput << " is " << (result ? "PRIME" : "NOT PRIME") << std::endl;
     
     if (!result)
     {
          std::cout << "Prime factors: ";
          int temp = numInput;
          for (int i = 2; i <= temp; i++)
          {
               while (temp % i == 0)
               {
                    std::cout << i << " ";
                    temp /= i;
               }
          }
          std::cout << std::endl;
     }
     
     return 0;
}

bool isPrime(int num)
{
     if (num < 2) return false;
     if (num == 2) return true;
     if (num % 2 == 0) return false;
     
     for (int n = 3; n * n <= num; n += 2) 
     {
          if (num % n == 0)
          {
               return false;
          }
     }
     return true;
}