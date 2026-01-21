#include <iostream>
#include <vector>

int main(void)
{
     std::vector<int> nums = {1, 2, 3, 4, 5};
     
     for (int num : nums)
     {
          num *=2;
          std::cout << "for each value:- " <<num <<std::endl;
     }
     
     for (int& num : nums)
     {
          num *=2;
          std::cout << "for each value:- " <<num <<std::endl;
     }
     return 0;
}