#include <iostream>
#include <limits>
#include <string>
#include <type_traits>

template <typename T>
T absValue(T num)
{
     static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic");
     return (num < 0) ? -num : num;
}

template <typename T>
T getInput(const std::string &prompt)
{
     T value;
     while (true)
     {
          std::cout << prompt;
          std::cin >> value;
          if (std::cin.fail())
          {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "Invalid input. Try again.\n";
          }
          else
          {
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               return value;
          }
     }
}

int main()
{
     int i = getInput<int>("Enter int: ");
     float f = getInput<float>("Enter float: ");
     double d = getInput<double>("Enter double: ");

     std::cout << "Abs of " << i << " is " << absValue(i) << std::endl;
     std::cout << "Abs of " << f << " is " << absValue(f) << std::endl;
     std::cout << "Abs of " << d << " is " << absValue(d) << std::endl;

     return 0;
}