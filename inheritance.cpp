#include <iostream>
#include <string>  

class Animal
{
public:
     std::string name; 
     int age; 
     
     void eat(void)
     {
          std::cout << name << " is eating" << '\n';
     }
     void sleeping(void)
     {
          std::cout << name << " is sleeping" << '\n';
     }
     void walking(void)
     {
          std::cout << name << " is walking" << '\n'; 
     }
};

class Dog : public Animal
{
public:
     int weight;
     std::string breed; 
     
     Dog(std::string x, int w, std::string b)
     {
          name = x;
          weight = w;
          breed = b;
          age = 0; 
          if (weight < 10)
          {
               this->eat();
          }
     }
     
    
     void bark()
     {
          std::cout << name << " says: Woof! Woof!" << '\n';
     }
     
     void displayInfo()
     {
          std::cout << "Name: " << name << ", Weight: " << weight 
                    << "kg, Breed: " << breed << '\n';
     }
};

class Cat : public Animal
{
public:
     std::string color;
     
     Cat(std::string n, std::string c)
     {
          name = n;
          color = c;
          age = 0;
     }
     
     void meow()
     {
          std::cout << name << " says: Meow!" << '\n';
     }
};

int main(void)
{
     Dog D1("Ramu", 5, "Labrador");
     D1.displayInfo();
     D1.bark();
     D1.walking();
     
     std::cout << '\n';
     
     Cat C1("Whiskers", "Orange");
     C1.meow();
     C1.sleeping();
     
     return 0;
}