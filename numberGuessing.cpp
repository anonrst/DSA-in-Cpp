#include <iostream>

int main()
{
     srand(time(NULL));
     int x = (rand() % 50) + 1;
     int no_guess = 0;
     while (true)
     {
          int userInput;
          std::cout << "guess Number:- ";
          std::cin >> userInput;
          no_guess++;
          if (userInput == x)
          break;
          std::cout << "guess => ";
          if (userInput > x)
          {
               std::cout << "too high";
          }
          else
          {
               std::cout << "too low";
          }
         
          std::cout << '\n';
     }
     std::cout <<"Guess: → Correct!\n" <<"guess Taken => "<<no_guess << std::endl;
}