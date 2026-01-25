#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>
#include <algorithm>
class Solution
{
public:
     int majorityElement(std::vector<int> &nums)
     {
          int ME = 0;
          int count = 0;
          for (int x : nums)
          {
               if (ME = x)
               {
                    ME = x;
                    count++;
               }
               else if (ME != x && count ==1)
               {

                    ME = x;
                    count = 0;
               }
          }
          return ME;
     }
};