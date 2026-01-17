#include <iostream>
#include <string.h>
#include <typeinfo>
int strLength(const char *start);
bool verifyLetterAndDigit(char *str, int length);
int main()
{
     char name[50];
     std::cout << "what's your Name? ";
     std::cin >> name;
     int strLen = strLength(name);
     if (6 <= strLen && strLen <= 12 && verifyLetterAndDigit(name, strLen))
     {
          std::cout << "valid Username" << std::endl;
     }
     else
     {
          std::cout << "InValid Username" << std::endl;
     }
}
bool verifyLetterAndDigit(char *str, int length)
{
     for (int i = 0; i < length; i++)
     {
          int ascii = str[i];
          if (!(65 <= ascii && ascii <= 90 || 97 <= ascii && ascii <= 122 || 48 <= ascii && ascii <= 57))
          {
               return false;
          }
     }
     return true;
}
int strLength(const char *start)
{
     const char *end = start;
     while (*end != '\0')
     {
          ++end;
          /* code */
     }
     return end - start;
}