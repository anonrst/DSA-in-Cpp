#include <iostream>

int main(void){

     enum leaders{ayan, matin, nabil};

     leaders val = matin;

     switch (val)
     {
     case  0:
          std::cout << "the upcoming leader is Ayan"  <<std::endl;
          break;
     
     case  1:
          std::cout << "the upcoming leader is matin"  <<std::endl;
          break;
     
     case  2:
          std::cout << "the upcoming leader is nabil"  <<std::endl;
          break;
     
     default:
     std::cout << "no one is the upcoming leader except nabil"  <<std::endl;
          break;
     }
     return 0;
}