#include <iostream>
#include <string.h>

int main()
{
     std::string name;
     std::cout << "plz Type your Name";
     std::getline(std::cin, name);
     if (name.empty())
     {
          std::cout << "something wen't wrong" << std::endl;
     }
     else if (name.length() > 12)
     {
          std::cout << "character limit execeeded " << std::endl;
     }
     else
     {
          std::cout << "your original name:- " << name << std::endl;
          std::cout << "name appended :- " << name.append(" always winning") << std::endl;
          std::cout << "letter at 3:- " << name.at(3) << std::endl;
          std::cout << "inserting in Name:- " << name.insert(3, "ok ") << std::endl;
     }
     return 0;
}