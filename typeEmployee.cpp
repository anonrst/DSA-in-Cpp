#include <iostream>

typedef struct employee{
     int ID;
     float salary;
}employee;

void printEmployee(employee Em);
int main(){
     employee e1;
     e1.ID = 101;
     e1.salary = 45000;
     printEmployee(e1);
     
     
}
void printEmployee(employee Em){
     using namespace std;
     cout<<"ID: "<<Em.ID<<" Salary: "<<Em.salary<<endl;
} 
