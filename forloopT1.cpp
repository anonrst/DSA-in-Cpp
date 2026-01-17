#include <iostream>
#include <vector>

int main(void)
{
     int n = 0;
     std::cout << "what is N? ";
     std::cin >> n;
     std::vector<int> bigDivs;
     for (int i = 1; i*i <= n; i++)
     {
          if (n % i == 0)
          {
               std::cout << i << " ";
               if(i != (n/i)){
                    bigDivs.push_back(n/i);

               }
          }
     }
     for(int j = bigDivs.size()-1; j >= 0; j--) std::cout << bigDivs[j] << " ";
     std::cout << std::endl;
     return 0;
}