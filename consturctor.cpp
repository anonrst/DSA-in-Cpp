#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>

class Student
{
private:
     int roll;
     std::string name;
     int grade;

public:
     Student() : roll(0), name(""), grade(0) {}

     Student(int r, const std::string &n, int g) : roll(r), name(n), grade(g)
     {
          validate();
     }

    
     Student(const Student &other) : roll(other.roll), name(other.name), grade(other.grade) {}

  
     ~Student() {}


     int getRoll() const { return roll; }
     std::string getName() const { return name; }
     int getGrade() const { return grade; }

     void setRoll(int r)
     {
          roll = r;
          validateRoll();
     }

     void setName(const std::string &n)
     {
          name = n;
          validateName();
     }

     void setGrade(int g)
     {
          grade = g;
          validateGrade();
     }

     void display() const
     {
          std::cout << "Roll: " << roll << ", Name: " << name << ", Grade: " << grade << std::endl;
     }

private:
     void validate()
     {
          validateRoll();
          validateName();
          validateGrade();
     }

     void validateRoll()
     {
          if (roll < 0)
               throw std::invalid_argument("Roll number must be non-negative.");
     }

     void validateName()
     {
          if (name.empty())
               throw std::invalid_argument("Name cannot be empty.");
          for (char c : name)
          {
               if (!isalpha(c) && !isspace(c))
                    throw std::invalid_argument("Name can only contain letters and spaces.");
          }
     }

     void validateGrade()
     {
          if (grade < 0 || grade > 100)
               throw std::invalid_argument("Grade must be between 0 and 100.");
     }
};

int getValidatedInt(const std::string &prompt, int min = INT_MIN, int max = INT_MAX)
{
     int value;
     while (true)
     {
          std::cout << prompt;
          std::cin >> value;
          if (std::cin.fail())
          {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "Invalid input. Please enter a valid integer.\n";
          }
          else if (value < min || value > max)
          {
               std::cout << "Value must be between " << min << " and " << max << ".\n";
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          }
          else
          {
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               return value;
          }
     }
}

std::string getValidatedString(const std::string &prompt)
{
     std::string value;
     while (true)
     {
          std::cout << prompt;
          std::getline(std::cin, value);
          if (!value.empty())
          {
               bool valid = true;
               for (char c : value)
               {
                    if (!isalpha(c) && !isspace(c))
                    {
                         valid = false;
                         break;
                    }
               }
               if (valid)
                    return value;
          }
          std::cout << "Invalid input. Name can only contain letters and spaces, and cannot be empty.\n";
     }
}

int main()
{
     try
     {
          std::vector<Student> students;
          int numStudents = getValidatedInt("Enter number of students: ", 1, 100);

          for (int i = 0; i < numStudents; ++i)
          {
               std::cout << "\nEntering details for student " << (i + 1) << ":\n";
               int roll = getValidatedInt("Enter roll number: ", 0);
               std::string name = getValidatedString("Enter name: ");
               int grade = getValidatedInt("Enter grade (0-100): ", 0, 100);

               students.emplace_back(roll, name, grade);
          }

          std::cout << "\nStudent Details:\n";
          for (const auto &student : students)
          {
               student.display();
          }

          if (!students.empty())
          {
               Student copy = students[0];
               std::cout << "\nCopy of first student:\n";
               copy.display();
          }
     }
     catch (const std::exception &e)
     {
          std::cerr << "Error: " << e.what() << std::endl;
          return 1;
     }

     return 0;
}