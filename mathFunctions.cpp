#include <iostream>
#include <cmath>
double calc(int selectedOption, double x, double y);
int main()
{
     double x;
     double y;
     int choosenOption;
     std::cout << "first num:- ";
     std::cin >> x;
     std::cout << "second num:- ";
     std::cin >> y;

     std::cout << "choose any options given blow:- " << std::endl;
     std::cout << "1)square root" << std::endl
               << "2)Power" << std::endl
               << "3)absolute difference" << std::endl
               << "4)Maximum" << std::endl
               << ">>>>  ";
     std::cin >> choosenOption;
     double valv = calc(choosenOption, x, y);

     std::cout << ">> " << valv << std::endl;
     return 0;
}

double calc(int selectedOption, double x, double y)
{
     if (selectedOption == 1)
     {
          return sqrt(x);
     }
     else if (selectedOption == 2)
     {
          return pow(x, y);
     }
     else if (selectedOption == 3)
     {

          return abs((int)(x - y));
     }
     else if (selectedOption == 4)
     {
          return fmax(x, y);
     }
     else
     {
          std::cout << "wrong option input";
          return 1;
     }
}