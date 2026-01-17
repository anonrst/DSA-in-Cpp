#include <iostream>

int main(void)
{
     srand(time(NULL));

     int value = (rand() % 6) + 1;
     std::cout << "Rolled: " << value << "\n"
               << ((value == 1) ? "Unlucky Roll" : (value == 6) ? "Lucky Role"
                                                                : "Normal Role")
               << std::endl;
}