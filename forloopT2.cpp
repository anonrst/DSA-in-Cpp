#include <iostream>
#include <string.h>

int main(void)
{
     std::string name ;
     std::cout << "what's your name? ";
     std::cin >> name;
     int freq[256] = {0};
     for(int i =0; i < name.size(); i++){
          freq[int(name[i])]++;
     }
     int count = 0;
     for(int i =0; i < 256; i++){
          if(freq[i] > 1) count++;
     }

     std::cout << "total count Value:- " << count << std::endl;
     return 0;
}