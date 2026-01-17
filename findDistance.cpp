#include <iostream>
#include <cmath>

int main()
{
     double x1 = 34.34;
     double x2 = 64.34;
     double y1 = 34.34;
     double y2 = 64.34;

     double distace = sqrt(pow((x1 - x2), 2) + (pow((y1 - y2), 2)));
     std::cout << "distance:= " << distace << std::endl;
}