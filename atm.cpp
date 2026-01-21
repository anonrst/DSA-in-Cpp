#include <iostream>
#include <vector>
#include <string>
#include <limits>

class ATM
{
private:
     double balance;
     std::vector<std::string> transactions;
     std::string pin;  

public:
     ATM(double initialBalance, std::string userPin) : balance(initialBalance), pin(userPin)  
     {
          transactions.push_back("Initial balance: " + std::to_string(balance));
     }

     bool verifyPin(std::string inputPin)
     {
          return inputPin == pin;
     }

     void checkBalance()
     {
          std::cout << "Current balance: $" << balance << std::endl;
     }

     void deposit(double amount)
     {
          if (amount <= 0)
          {
               std::cout << "Deposit amount must be positive.\n";
               return;
          }
          balance += amount;
          transactions.push_back("Deposited: $" + std::to_string(amount));
          std::cout << "Deposited $" << amount << ". New balance: $" << balance << std::endl;
     }

     void withdraw(double amount)
     {
          if (amount <= 0)
          {
               std::cout << "Withdrawal amount must be positive.\n";
               return;
          }
          if (amount > balance)
          {
               std::cout << "Insufficient funds.\n";
               return;
          }
          balance -= amount;
          transactions.push_back("Withdrew: $" + std::to_string(amount));
          std::cout << "Withdrew $" << amount << ". New balance: $" << balance << std::endl;
     }

     void showTransactions()
     {
          std::cout << "Transaction history:\n";
          for (const auto &t : transactions)
          {
               std::cout << t << std::endl;
          }
     }
};

double getValidatedAmount(const std::string &prompt)
{
     double amount;
     while (true)
     {
          std::cout << prompt;
          std::cin >> amount;
          if (std::cin.fail() || amount < 0)
          {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "Invalid amount. Please enter a positive number.\n";
          }
          else
          {
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               return amount;
          }
     }
}

int getValidatedOption()
{
     int opt;
     while (true)
     {
          std::cout << "1 -> Check Balance\n2 -> Deposit\n3 -> Withdraw\n4 -> Transaction History\n5 -> Exit\n>>> ";
          std::cin >> opt;
          if (std::cin.fail() || opt < 1 || opt > 5)
          {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "Invalid option. Choose 1-5.\n";
          }
          else
          {
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               return opt;
          }
     }
}

int main()
{
     std::string pin;
     std::cout << "Enter PIN: ";
     std::cin >> pin;
     std::cin.ignore();
     
     ATM atm(10000.0, pin);
     
     std::string inputPin;
     std::cout << "Verify PIN: ";
     std::cin >> inputPin;
     std::cin.ignore();
     
     if (!atm.verifyPin(inputPin))
     {
          std::cout << "Incorrect PIN. Access denied.\n";
          return 1;
     }
     
     std::cout << "PIN verified. Welcome!\n\n";
     
     while (true)
     {
          int opt = getValidatedOption();
          if (opt == 5)
               break;
          switch (opt)
          {
          case 1:
               atm.checkBalance();
               break;
          case 2:
               atm.deposit(getValidatedAmount("Deposit amount: $"));
               break;
          case 3:
               atm.withdraw(getValidatedAmount("Withdraw amount: $"));
               break;
          case 4:
               atm.showTransactions();
               break;
          }
     }
     return 0;
}