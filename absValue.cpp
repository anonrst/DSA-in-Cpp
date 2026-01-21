#include <iostream>
#include <limits>
#include <string>
#include <vector> 

template <typename T>
T absValue(T num)
{
    return (num < 0) ? -num : num;
}

template <typename T>
T getValidatedInput(const std::string &prompt)
{
    T value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main()
{
    int count = getValidatedInput<int>("How many numbers? ");
    std::vector<int> numbers;
    
    for (int i = 0; i < count; ++i)
    {
        int num = getValidatedInput<int>("Enter number: ");
        numbers.push_back(num);
    }
    
    std::cout << "\nResults:\n";
    int sum = 0; 
    for (int num : numbers)
    {
        int abs = absValue(num);
        std::cout << "|" << num << "| = " << abs << '\n';
        sum += abs;
    }
    
    std::cout << "\nSum of absolute values: " << sum << '\n';
    
    return 0;
}