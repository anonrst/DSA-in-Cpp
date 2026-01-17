#include <iostream>
void days(int num);
int main()
{
     int day;
     std::cout << "what's N? ";
     std::cin >> day;
     days(day);
     return 0;
}
void days(int num)
{
     using namespace std;
     switch (num)
     {
     case 1:
     case 2:
     case 3:
     case 4:
     case 5:
          cout << "weekDay" << endl;
          break;
     case 6:
     case 7:
          cout << "weekend" << endl;
          break;
     default:
          cout << "Invalid" << endl;
          break;
     }
}