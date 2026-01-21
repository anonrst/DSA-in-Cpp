#include <iostream>
#include <iomanip>

double calculateTax(double income, int &taxPercentage)
{
     if (income <= 250000)
     {
          taxPercentage = 0;
          return 0;
     }
     else if (income < 500000)
     {
          taxPercentage = 5;
          return (income * taxPercentage) / 100;
     }
     else if (income < 1000000)
     {
          taxPercentage = 20;
          return (income * taxPercentage) / 100;
     }
     else
     {
          taxPercentage = 30;
          return (income * taxPercentage) / 100;
     }
}

int main()
{
     using namespace std;
     double income;
     int taxPercentage;
     
     cout << "Enter your annual income: $";
     cin >> income;
     
     if (income < 0) 
     {
          cout << "Invalid income!" << endl;
          return 1;
     }
     
     double taxAmount = calculateTax(income, taxPercentage); 
     double netIncome = income - taxAmount;
     
     cout << fixed << setprecision(2);
     cout << "\n=== Tax Calculation ===\n"; 
     cout << "Gross Income: $" << income << endl;
     cout << "Tax Percentage: " << taxPercentage << "%" << endl;
     cout << "Tax Amount: $" << taxAmount << endl;
     cout << "Net Income: $" << netIncome << endl;
     
     return 0;
}
