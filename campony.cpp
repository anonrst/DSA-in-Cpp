#include <iostream>
namespace comapany{
     namespace HR{
          int totalEmployee = 34;
          int show(){
               return totalEmployee;
          }
     }
}
int main(){
using namespace std;
     using namespace comapany::HR;
     cout << "total employee:- "<< comapany::HR::totalEmployee<<endl;
     cout << "total employee:- " << show()<< endl;
     return 0;

}