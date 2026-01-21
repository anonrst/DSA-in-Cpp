#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

class Pizza
{
private:
     std::vector<std::string> toppings;
     double basePrice;
     std::string size;

public:
     Pizza() : basePrice(10.0), size("Medium") {}

     Pizza(const std::string &s) : basePrice(10.0), size(s) {}

     Pizza(const std::string &s, const std::vector<std::string> &t) : basePrice(10.0), size(s), toppings(t) {}

     void addTopping(const std::string &topping)
     {
          if (std::find(toppings.begin(), toppings.end(), topping) == toppings.end())
          {
               toppings.push_back(topping);
          }
     }

     void removeTopping(const std::string &topping)
     {
          auto it = std::find(toppings.begin(), toppings.end(), topping);
          if (it != toppings.end())
          {
               toppings.erase(it);
          }
     }

     double calculatePrice() const
     {
          double price = basePrice;
          if (size == "Large")
               price += 5.0;
          else if (size == "Small")
               price -= 2.0;
          price += toppings.size() * 1.5;
          return price;
     }

     void display() const
     {
          std::cout << "Size: " << size << ", Toppings: ";
          for (size_t i = 0; i < toppings.size(); ++i)
          {
               std::cout << toppings[i];
               if (i < toppings.size() - 1)
                    std::cout << ", ";
          }
          std::cout << ", Price: $" << calculatePrice() << std::endl;
     }
};

std::string getValidatedSize()
{
     std::string size;
     while (true)
     {
          std::cout << "Size (Small/Medium/Large): ";
          std::getline(std::cin, size);
          if (size == "Small" || size == "Medium" || size == "Large")
               return size;
          std::cout << "Invalid size.\n";
     }
}

std::vector<std::string> getToppings()
{
     std::vector<std::string> toppings;
     std::string topping;
     std::cout << "Enter toppings (type 'done' to finish):\n";
     while (true)
     {
          std::cout << "Topping: ";
          std::getline(std::cin, topping);
          if (topping == "done")
               break;
          toppings.push_back(topping);
     }
     return toppings;
}

int main()
{
     Pizza pizza1;
     pizza1.display();

     std::string size = getValidatedSize();
     std::vector<std::string> tops = getToppings();
     Pizza pizza2(size, tops);
     pizza2.display();

     // Interactive ordering
     Pizza order;
     order = Pizza(getValidatedSize(), getToppings());
     order.display();

     return 0;
}