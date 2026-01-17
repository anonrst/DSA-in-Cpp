#include <iostream>
#include <string.h>

bool isPalinndrome(std::string str);
int main()
{
     std::string input;
     std::cout << "plz enter your name:- ";
     std::cin >> input;
     bool isValid = isPalinndrome(input);
     std::cout << (isValid ? "it's Valid" : "it's not Valid") << std::endl;
     ;
     return 0;
}

bool isPalinndrome(std::string str)
{
     int strSize = str.length();
     std::cout << "str size:- " << strSize << std::endl;
     for (int i = 0; i < strSize / 2; i++)
     {
          if (str[i] != str[strSize - (i + 1)])
          {
               return false;
          }
     }
     return true;
}