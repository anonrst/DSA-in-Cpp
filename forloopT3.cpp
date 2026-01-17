#include <iostream>
#include <string.h>

int main(void)
{
     int num = 0;
     std::cout << "what is num? ";
     std::cin >> num;
     int total = 0;
     for (int i = 1; i * i <= num; i++)
     {
          if (num % i == 0)
          {
               total = total + i + (num / i);
               if (i == num / i)
               {
                    total = total - i;
               }
          }
     }
     total = total - num;
     std::cout << ((total == num) ? "True" : "False") << std::endl;
     return 0;
}
