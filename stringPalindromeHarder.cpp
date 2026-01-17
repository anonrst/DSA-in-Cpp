#include <iostream>
#include <string.h>
std::string clearStrings(std::string str);
bool isPalinndrome(std::string str);
int main()
{
     std::string input;
     std::cout << "plz enter your name:- ";
     getline(std::cin, input);

     bool isValid = isPalinndrome(clearStrings(input));
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
std::string clearStrings(std::string input)
{
     int n = 0;
     std::string value;
     while(input[n] != '\0')
     {
          int asciiV = input[n];
          if (65 <= asciiV && asciiV <= 90 || 97 <= asciiV && asciiV <= 122 || 48<= asciiV && asciiV <= 57)
          {
               value.push_back(input[n]);
          }
          n++;
     }

     return value;
}