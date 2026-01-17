#include <iostream>
#include <iomanip>
double calculateAverage(int s1, int s2, int s3);
int main(){
     using namespace std;
     int s1 = 21;
     int s2 = 32; 
     int s3 = 29;
double vaue =  calculateAverage(s1, s2, s3);
cout << fixed << setprecision(2);
if(vaue > 50){
     cout << "pass with:- "<<vaue <<endl;
}else{
     cout << "fail with:- "<<vaue <<endl;
}
}

double calculateAverage(int s1, int s2, int s3){
     return (s1+ s2+s3)/ 3.0;
}