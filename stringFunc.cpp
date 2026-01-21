#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <limits>
#include <algorithm>

class StringProcessor
{
public:
     static bool isValidName(const std::string &name)
     {
          std::regex pattern("^[a-zA-Z ]+$");
          return std::regex_match(name, pattern) && name.length() >= 3 && name.length() <= 50;
     }
     static std::string reverseString(const std::string &str)
     {
          std::string rev = str;
          std::reverse(rev.begin(), rev.end());
          return rev;
     }
     static bool isPalindrome(const std::string &str)
     {
          std::string clean;
          for (char c : str)
          {
               if (isalnum(c))
                    clean += tolower(c);
          }
          std::string rev = clean;
          std::reverse(rev.begin(), rev.end());
          return clean == rev;
     }
     static std::string toUpperCase(const std::string &str)
     {
          std::string upper = str;
          std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
          return upper;
     }
     static std::string toLowerCase(const std::string &str)
     {
          std::string lower = str;
          std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
          return lower;
     }
     static int countVowels(const std::string &str)
     {
          int count = 0;
          for (char c : str)
          {
               char lower = tolower(c);
               if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    count++;
          }
          return count;
     }
};

std::string getValidatedString(const std::string &prompt)
{
     std::string str;
     while (true)
     {
          std::cout << prompt;
          std::getline(std::cin, str);
          if (!str.empty())
               return str;
          std::cout << "Input cannot be empty." << std::endl;
     }
}

int main()
{
     std::vector<std::string> strings;
     int num;
     std::cout << "How many strings to process? ";
     std::cin >> num;
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     for (int i = 0; i < num; ++i)
     {
          std::string str = getValidatedString("Enter string: ");
          strings.push_back(str);
     }
     for (const auto &str : strings)
     {
          std::cout << "\n=== Processing: " << str << " ===\n"; 
          std::cout << "Valid name: " << (StringProcessor::isValidName(str) ? "Yes" : "No") << std::endl;
          std::cout << "Reversed: " << StringProcessor::reverseString(str) << std::endl;
          std::cout << "Palindrome: " << (StringProcessor::isPalindrome(str) ? "Yes" : "No") << std::endl;
          std::cout << "Upper: " << StringProcessor::toUpperCase(str) << std::endl;
          std::cout << "Lower: " << StringProcessor::toLowerCase(str) << std::endl;
          std::cout << "Vowel count: " << StringProcessor::countVowels(str) << std::endl;
          std::cout << "Length: " << str.length() << std::endl;
     }
     return 0;
}