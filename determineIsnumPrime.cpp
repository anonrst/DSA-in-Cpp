#include <iostream>

int main()
{
     int numInput;
     std::cout << "what's number:- ";
     std::cin >> numInput;
     int n = 2;
     bool val = true;
     while (n < (numInput / 2))
     {
          if (numInput % n == 0)
          {
               val = false;
               break;
          }
          n++;
     }
     std::cout << "vaue:- " << ((val) ? "True" : "False") << std::endl;
}