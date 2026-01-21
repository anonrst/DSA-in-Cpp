#include <iostream>

class Cmonitor
{
public:
     int grossM = 1000;
     std::string name;
     int rollNo;
     int totalMarks;

     void details(void)
     {
          std::cout << "the name of Cmonitor is:- " << name << '\n';
          std::cout << "the rollNo of Cmonitor is " << rollNo << '\n';
          std::cout << "the totalMarks of Cmonitor is:- " << totalMarks << '\n';
     }
     void calGrade()
     {
          std::cout << "the totalMarks of Cmonitor is:- " << (totalMarks * 100) / grossM << "%\n";
     }
};

int main(void)
{
     Cmonitor riya;
     riya.name = "ayan";
     riya.totalMarks = 400;
     riya.rollNo = 'A';
     riya.calGrade();
     riya.details();
     return 0;
}