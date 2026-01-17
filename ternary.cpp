#include <iostream>

int main()
{
     int input;
     std::cout << "what's N? ";
     std::cin >> input;
     (input >= 0) ? std::cout << "Absolute value:- " << input << std::endl : std::cout << "Absolute value:- " << -input << std::endl;
     return 0;
}
