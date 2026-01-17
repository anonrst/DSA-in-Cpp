#include <iostream>
#include <iomanip>
int main()
{
     using namespace std;
     double income;
     double taxAmount;
     double netIncome;
     int taxPercentage;
     cout << "how much is your income? ";
     cin >> income;
     if (income <= 250000)
     {
          taxPercentage = 0;
          taxAmount = 0;
          netIncome = income;
     }
     else if (income < 500000)
     {
          taxPercentage = 5;
          taxAmount = (income * taxPercentage) / 100;
          netIncome = income - taxAmount;
     }
     else if (income < 1000000)
     {
          taxPercentage = 20;
          taxAmount = (income * taxPercentage) / 100;
          netIncome = income - taxAmount;
     }
     else if (income >= 1000000)
     {
          taxPercentage = 30;
          taxAmount = (income * taxPercentage) / 100;
          netIncome = income - taxAmount;
     }
     else
     {
          return 1;
     }
     cout << fixed << setprecision(2);
     cout << "tax percentage:- " << taxPercentage << endl;
     cout << "tax Amount:- " << taxAmount << endl;
     cout << "net Income:- " << netIncome << endl;
     return 0;
}
