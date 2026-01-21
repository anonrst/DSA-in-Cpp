#include <iostream>

int main(void){
     FILE *Ofile = fopen("newFile.txt", "a");
     if(Ofile == NULL){
          return 1;
     }
     char name[50];
     char number[12];
     std::cout << "what is your Name:- ";
     std::cin >>name;
     std::cout << "Now Number:- ";
     std::cin >>  number;
     fprintf(Ofile,"Name:- %s ,Number:- %s\n", name, number );
     fclose(Ofile);
     return 0;
}