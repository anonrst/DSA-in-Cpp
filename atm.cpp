#include <iostream>
void atmOptions(int opt, double &initialBalance);
int main()
{
     double initialBalance = 10000;
     int opt;
     while (true)
     {
          std::cout << "1 -> check Balance " << std::endl
                    << "2 -> deposit Balance " << std::endl
                    << "3 -> withdraw " << std::endl
                    << "4 -> Exit" << std::endl
                    << ">>> ";

          std::cin >> opt;
          if (opt == 4)
          {
               break;
          }
          atmOptions(opt, initialBalance);
     }

     return 0;
}
void atmOptions(int opt, double &initialBalance)
{
     switch (opt)
     {
     case 1:
     {

          std::cout << "balance:- " << initialBalance << std::endl;
          break;
     }
     case 2:
     {

          double depositAmount;
          std::cout << "Amount:- ";
          std::cin >> depositAmount;
          initialBalance += depositAmount;
          break;
     }
     case 3:
     {
          double withdrawAmount;
          std::cout << "Amount:- ";
          std::cin >> withdrawAmount;
          if (withdrawAmount <= initialBalance)
          {
               initialBalance -= withdrawAmount;
          }
          else
          {
               std::cout << "unSufficient Balance\n";
          }
          break;
     }
     default:
          std::cout << "choose valid option (1-4)" << std::endl;
          break;
     }
}