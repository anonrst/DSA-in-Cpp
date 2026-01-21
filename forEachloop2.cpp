#include <iostream>
#include <vector>

int main(void)
{
     std::vector<int> nums = {1, 2};
     int sum = 0;
     int count = 0;
     for (int single : nums)
     {
          if (single % 2 == 0)
          {
               sum += single;
          }
          if (single > 10)
          {
               count++;
          }
     }
     std::cout << "total sum  of even:- " << sum << std::endl;
     std::cout << "total count  of nums:- " << count << std::endl;
     return 0;
}