#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
     const int SIZE = 20;
     std::string foods[SIZE];
     std::fill(foods, foods + (SIZE / 2), "ayan");
     std::fill(foods + (SIZE / 2), foods + (SIZE - 5), "umme");
     for (std::string name : foods)
     {
          std::cout << name << '\n';
     }
     return 0;
}