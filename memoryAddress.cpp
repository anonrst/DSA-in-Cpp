#include <iostream>
struct  Config 
{
     int volume;
     int brightness;
     int mode;
};
void updateByValue(Config con);
void updateByReference(Config& con);
void updateByPOinter(Config *con);
int main(void)
{ 
     Config C1;
     C1.volume = 100;
     C1.mode = 100;
     C1.brightness = 100;
     Config *pC1 =&C1;
     updateByValue(C1);
     std::cout << "Volume:- "<<C1.volume <<std::endl;
     std::cout << "Brightness:- "<<C1.brightness << std::endl;
     std::cout << "Mpde:- "<< C1.mode<< std::endl;
     updateByReference(C1);
     std::cout << "Volume:- "<<C1.volume <<std::endl;
     std::cout << "Brightness:- "<<C1.brightness << std::endl;
     std::cout << "Mpde:- "<< C1.mode<< std::endl;
     updateByPOinter(pC1);
     std::cout << "Volume:- "<<C1.volume <<std::endl;
     std::cout << "Brightness:- "<<C1.brightness << std::endl;
     std::cout << "Mpde:- "<< C1.mode<< std::endl;
     return 0;
}

void updateByValue(Config con)
{
     std::cout << "A] updateByValue: ";
     con.mode = 90;
     con.brightness = 90;
     con.volume = 90;
};
void updateByReference(Config& con)
{
     std::cout << "\nB] updateByReference: ";
     con.mode = 80;
     con.brightness = 80;
     con.volume = 80;
};
void updateByPOinter(Config* con)
{
     std::cout << "\nC] updateByPOinter: ";
     con->mode = 70;
     con->brightness = 70;
     con->volume = 70;
};