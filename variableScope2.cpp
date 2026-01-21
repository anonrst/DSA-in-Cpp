#include <iostream>
int* getNum(void);
int main(void){
int *value = getNum();
std::cout << value << std::endl;
}

int* getNum(void){
     int num  = 100;
     return &num;
     
}