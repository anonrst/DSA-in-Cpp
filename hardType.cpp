#include <iostream>
#include <iomanip>

int main(){
     using namespace std;
     int num = 98;
     float decimal  = 43.4082;
     double bigDec = 2.194578223;
     char letter= 'A';
     double doubleOutput =num + (float)decimal+ bigDec+ (int)letter;
     int integerOutput =num + (int)decimal+ (int)bigDec+ (int)letter;
     cout << fixed << setprecision(2);
     cout << "Double result: "<<doubleOutput<< endl;
     cout << "Int result: "<<integerOutput<< endl;

}