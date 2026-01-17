#include <iostream>

int main(){
     std::string input = "ayan shailkh";
     char vovwels[5] = {'a', 'e', 'i', 'o', 'u'};
     int numC = 0;
     int n = 0;
     while(input[n] != '\0'){
          if(input[n] == vovwels[0]|| input[n] == vovwels[1]||input[n] == vovwels[2]||input[n] == vovwels[3]||input[n] == vovwels[4]){
               numC++;
          }
          n++;
     }
     std::cout << "total numbers pf vowels:- "<< numC <<std::endl;
     return 0;
}