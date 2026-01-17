#include <iostream>

int main()
{
     int grade;
     std::cout << "what's grade? ";
     std::cin >> grade;
     std::cout << ((grade >= 90) ? "Excellent" : (grade >= 60) ? "Pass"
                                                               : "Fail")
               << std::endl;
     return 0;
}
