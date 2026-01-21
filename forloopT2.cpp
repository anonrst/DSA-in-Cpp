#include <iostream>
#include <string>
#include <map> 

int main(void)
{
     std::string name;
     std::cout << "Enter a string: ";
     std::cin >> name;
     
     std::map<char, int> freq;  
     
     // Count frequency
     for(int i = 0; i < name.size(); i++){
          freq[name[i]]++;
     }
     
     int count = 0;
     std::cout << "\nCharacters appearing more than once:\n";  
     for(auto &pair : freq){  
          if(pair.second > 1) {
               std::cout << "'" << pair.first << "' appears " << pair.second << " times\n";
               count++;
          }
     }
     
     std::cout << "\nTotal repeating characters: " << count << std::endl;
     return 0;
}