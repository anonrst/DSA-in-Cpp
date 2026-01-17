#include <iostream>
void swap(int &x, int &y);
int main()
{
     using namespace std;
     int x = 12;
     int y = 23;
     cout << "before swap x:- " << x << " y:- " << y << endl;
     swap(x, y);
     cout << "after swap x:- " << x << " y:- " << y << endl;
     return 0;
}

void swap(int &x, int &y)
{
     int temp = y;
     y = x;
     x = temp;
}