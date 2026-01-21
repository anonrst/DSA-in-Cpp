#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <stdexcept>

class StrongNumberChecker
{
public:
     static long long factorial(int n)
     {
          if (n < 0)
               throw std::invalid_argument("Negative number");
          long long fact = 1;
          for (int i = 1; i <= n; ++i)
          {
               if (fact > LLONG_MAX / i)
                    throw std::overflow_error("Factorial overflow");
               fact *= i;
          }
          return fact;
     }
     static bool isStrongNumber(long long num)
     {
          if (num < 0)
               return false;
          long long original = num;
          long long sum = 0;
          while (num > 0)
          {
               int digit = num % 10;
               sum += factorial(digit);
               num /= 10;
          }
          return sum == original;
     }
};

long long getValidatedLongLong(const std::string &prompt)
{
     long long val;
     while (true)
     {
          std::cout << prompt;
          std::cin >> val;
          if (std::cin.fail())
          {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "Invalid input. Enter a valid number." << std::endl;
          }
          else
          {
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               return val;
          }
     }
}

int main()
{
     std::vector<long long> numbers;
     int count;
     std::cout << "How many numbers to check? ";
     count = getValidatedLongLong("");
     for (int i = 0; i < count; ++i)
     {
          long long num = getValidatedLongLong("Enter number: ");
          numbers.push_back(num);
     }
     for (auto num : numbers)
     {
          try
          {
               bool isStrong = StrongNumberChecker::isStrongNumber(num);
               std::cout << num << " is " << (isStrong ? "a strong number." : "not a strong number.") << std::endl;
          }
          catch (const std::exception &e)
          {
               std::cout << "Error checking " << num << ": " << e.what() << std::endl;
          }
     }
     return 0;
}