#include <iostream>

int main()
{
     int input;
     std::cout << "Enter a number: ";
     std::cin >> input;
     
     // Original: absolute value
     int absVal = (input >= 0) ? input : -input;
     std::cout << "Absolute value: " << absVal << std::endl;
     
     std::string evenOdd = (input % 2 == 0) ? "Even" : "Odd";
     std::cout << "Number is: " << evenOdd << std::endl;
     
     std::string sign = (input > 0) ? "Positive" : (input < 0) ? "Negative" : "Zero";
     std::cout << "Sign: " << sign << std::endl;
     
     return 0;
}
