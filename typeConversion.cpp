#include <iostream>

int main()
{
     int item1 = 45;
     using namespace std;
     float item2 = 32.75;
     double item3 = 120.5;
     double totalBeforeDiscount = item1 + item2 + item3;
     double netDiscount =(totalBeforeDiscount*10)/100;
     double totalafteriscount = totalBeforeDiscount - netDiscount;
     int roundedDiscount = totalafteriscount;
     cout << "Total before discount: " << totalBeforeDiscount << endl;
     cout << "Discounted total: " << totalafteriscount << endl;
     cout << "Rounded total: " << roundedDiscount << endl;
}