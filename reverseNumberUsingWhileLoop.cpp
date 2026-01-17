#include <iostream>

int main()
{
     int num;
     std::cout << "what is number:- ";
     std::cin >> num;
     int value = 0;
     while (num > 0)
     {
          int lastDigit = num % 10;
          std::cout << "current Digit:- " << lastDigit<<std::endl;
          value = (lastDigit + (value*10));
          num /= 10;
          std::cout << "now Value:- " << num<<std::endl;
     }
     std::cout << value <<std::endl; 
     return 0;
}

