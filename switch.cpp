#include <iostream>
#include <string>  

void days(int num);
std::string getDayName(int num);  

int main()
{
     int day;
     std::cout << "Enter day number (1-7): ";
     std::cin >> day;
     days(day);
     std::cout << "Day name: " << getDayName(day) << std::endl;
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
          cout << "Weekday" << endl;
          break;
     case 6:
     case 7:
          cout << "Weekend" << endl;
          break;
     default:
          cout << "Invalid day number" << endl;
          break;
     }
}

std::string getDayName(int num)
{
     switch (num)
     {
     case 1: return "Monday";
     case 2: return "Tuesday";
     case 3: return "Wednesday";
     case 4: return "Thursday";
     case 5: return "Friday";
     case 6: return "Saturday";
     case 7: return "Sunday";
     default: return "Invalid";
     }
}