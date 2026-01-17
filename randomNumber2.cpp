#include <iostream>
void isPrime(int num, bool &wasPrime);
int main()
{
     srand(time(NULL));
     while (true)
     {
          int x = (rand() % 100) + 1;
          bool wasPrime = true;
          if (x == 1)
          {
               wasPrime = false;
               std::cout << "normal random number:- " << x << std::endl;
          }
          isPrime(x, wasPrime);
          if (wasPrime)
          {
               std::cout << "Prime random number:- " << x << std::endl;
               break;
          }
     }

     return 0;
}
void isPrime(int num, bool &wasPrime)
{
     for (int i = 2; i * i <= num; i++)
     {
          if (num % i == 0)
          {
               std::cout << "normal random number:- " << num << std::endl;
               wasPrime = false;
               break;
          }
     }
}