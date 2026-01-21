#include <iostream>

void swapNumbers(int &a, int &b)
{
     a = a + b;
     b = a - b;
     a = a - b;
}

int main()
{
     using namespace std;
     int num1, num2; 
     cout << "Enter first number: ";
     cin >> num1;
     cout << "Enter second number: ";
     cin >> num2;
     
     cout << "Before swap - num1: " << num1 << ", num2: " << num2 << endl;
     swapNumbers(num1, num2);
     cout << "After swap - num1: " << num1 << ", num2: " << num2 << endl;
     
     cout << "\nSwapping again...\n";
     swapNumbers(num1, num2);
     cout << "After 2nd swap - num1: " << num1 << ", num2: " << num2 << endl;
     
     return 0;
}
