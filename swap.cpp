#include <iostream>

int main()
{
     using namespace std;
     int num1 = 2932;
     int num2 = 124;
     cout << "num1:- " << num1 << " num2:- " << num2 << endl;
     num1 = num1 + num2;
     num2 = num1 - num2;
     num1 = num1 - num2;
     cout << "num1 after swap :- " << num1 << " num2 after swap:- " << num2 << endl;
}
