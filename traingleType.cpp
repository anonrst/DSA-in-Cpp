#include <iostream>
void typeOfTraingle(float n1, float n2, float n3);
int main()
{
     float side1 = 7;
     float side2 = 3;
     float side3 = 3;
     typeOfTraingle(side1, side2, side3);
     return 0;
}

void typeOfTraingle(float n1, float n2, float n3)
{
     if (!((n1 + n2) > n3 && (n2 + n3) > n1 && (n1 + n3) > n2))
     {
          std::cout << "this is not Traingle" << std::endl;
     }
     else if (n1 == n2 && n2 == n3)
     {
          std::cout << "equilateral traingle" << std::endl;
     }
     else if (n1 == n2 && n1 != n3 || n2 == n3 && n2 != n1 || n3 == n1 && n3 != n2)
     {
          std::cout << "isosceles triangle" << std::endl;
     }
     else
     {
          std::cout << "scalan traingle" << std::endl;
     }
}