#include <iostream>

int main()
{
     srand(time(NULL));
     int x = (rand() % 50) + 1;
     int no_guess = 0;
     int maxAttempts = 7; 
     
     std::cout << "Guess the number between 1 and 50\n";
     std::cout << "You have " << maxAttempts << " attempts.\n\n"; 
     while (no_guess < maxAttempts)
     {
          int userInput;
          std::cout << "Attempt " << (no_guess + 1) << "/" << maxAttempts << " - Guess: "; 
          std::cin >> userInput;
          no_guess++;
          
          if (userInput == x)
          {
               std::cout << "\nCorrect! You won in " << no_guess << " attempts!\n";
               return 0; 
          }
          
          std::cout << "guess => ";
          if (userInput > x)
          {
               std::cout << "too high";
          }
          else
          {
               std::cout << "too low";
          }
          
          int remaining = maxAttempts - no_guess;
          if (remaining > 0)
          {
               std::cout << " (" << remaining << " attempts left)";
          }
          std::cout << '\n';
     }
     
     std::cout << "\nGame Over! The number was " << x << std::endl;
     return 0;
}