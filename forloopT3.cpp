#include <iostream>

int main(void)
{
     int num = 0;
     std::cout << "Enter a number: ";
     std::cin >> num;
     
     int total = 0;
     std::cout << "Divisors (excluding " << num << "): ";  
     
     for (int i = 1; i * i <= num; i++)
     {
          if (num % i == 0)
          {
               total = total + i + (num / i);
               if (i == num / i)
               {
                    total = total - i;
               }
               if (i != num) std::cout << i << " ";
               if (i != num/i && num/i != num) std::cout << num/i << " ";
          }
     }
     total = total - num;
     
     std::cout << "\nSum of divisors: " << total << std::endl;  
     
     // Check if perfect number
     if (total == num)
          std::cout << num << " is a PERFECT number!" << std::endl;
     else if (total > num)
          std::cout << num << " is an ABUNDANT number" << std::endl;  
     else
          std::cout << num << " is a DEFICIENT number" << std::endl;
     
     return 0;
}
