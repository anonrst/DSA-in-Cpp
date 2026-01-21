#include <iostream>
void update(void);
int Int = 100;
int main(void)
{

     for (int i = 0; i < 2; i++)
     {

          int Int = 100;
          std::cout << "loopInt:- " << Int << std::endl;
     }
     update();
     std::cout << "localInt:- " << Int << std::endl;
     return 0;
}

void update(void)
{
     int Int = 100;
     std::cout << "updateInt:- " << Int << std::endl;
}