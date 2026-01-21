#include <iostream>
#include <vector>

int main(void)
{
     int n = 0;
     std::cout << "Enter a number: ";
     std::cin >> n;
     
     std::vector<int> bigDivs;
     int count = 0;
     
     std::cout << "Divisors of " << n << ": ";
     for (int i = 1; i*i <= n; i++)
     {
          if (n % i == 0)
          {
               std::cout << i << " ";
               count++; 
               if(i != (n/i)){
                    bigDivs.push_back(n/i);
                    count++;
               }
          }
     }
     for(int j = bigDivs.size()-1; j >= 0; j--) 
          std::cout << bigDivs[j] << " ";
     
     std::cout << "\nTotal divisors: " << count << std::endl;
     int sqrt_n = 1;
     while (sqrt_n * sqrt_n < n) sqrt_n++;
     if (sqrt_n * sqrt_n == n)
          std::cout << n << " is a perfect square!" << std::endl;
     
     return 0;
}