#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <memory>
#include <fstream>
#include <sstream>
#include <algorithm>

class Employee
{
private:
     std::string name;
     int id;
     double salary;

public:
     Employee(std::string n, int i, double s) : name(n), id(i), salary(s) {}
     virtual ~Employee() {}
     virtual void display() const
     {
          std::cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << std::endl;
     }
     virtual std::string getType() const { return "Employee"; }
     virtual void save(std::ofstream &file) const
     {
          file << getType() << "," << id << "," << name << "," << salary << std::endl;
     }
     int getId() const { return id; }
     std::string getName() const { return name; }
     double getSalary() const { return salary; }
     void setSalary(double s) { salary = s; }
};

class Manager : public Employee
{
private:
     int teamSize;

public:
     Manager(std::string n, int i, double s, int ts) : Employee(n, i, s), teamSize(ts) {}
     void display() const override
     {
          Employee::display();
          std::cout << "Team Size: " << teamSize << std::endl;
     }
     std::string getType() const override { return "Manager"; }
     void save(std::ofstream &file) const override
     {
          file << getType() << "," << getId() << "," << getName() << "," << getSalary() << "," << teamSize << std::endl;
     }
};

class HR
{
private:
     std::vector<std::unique_ptr<Employee>> employees;

public:
     void addEmployee(std::unique_ptr<Employee> emp)
     {
          employees.push_back(std::move(emp));
     }
     void removeEmployee(int id)
     {
          auto it = std::find_if(employees.begin(), employees.end(), [id](const std::unique_ptr<Employee> &e)
                                 { return e->getId() == id; });
          if (it != employees.end())
          {
               employees.erase(it);
               std::cout << "Employee removed.\n";
          }
          else
          {
               std::cout << "Employee not found.\n";
          }
     }
     void listEmployees() const
     {
          for (const auto &emp : employees)
          {
               emp->display();
          }
     }
     int totalEmployees() const
     {
          return employees.size();
     }
     void updateSalary(int id, double newSalary)
     {
          for (auto &emp : employees)
          {
               if (emp->getId() == id)
               {
                    emp->setSalary(newSalary);
                    std::cout << "Salary updated.\n";
                    return;
               }
          }
          std::cout << "Employee not found.\n";
     }
     void sortEmployeesBySalary()
     {
          std::sort(employees.begin(), employees.end(), [](const std::unique_ptr<Employee> &a, const std::unique_ptr<Employee> &b)
                    { return a->getSalary() < b->getSalary(); });
     }
     void searchEmployeeByName(const std::string &name)
     {
          for (const auto &emp : employees)
          {
               if (emp->getName() == name)
               {
                    emp->display();
                    return;
               }
          }
          std::cout << "Not found.\n";
     }
     void saveToFile(const std::string &filename)
     {
          std::ofstream file(filename);
          for (const auto &emp : employees)
          {
               emp->save(file);
          }
     }
     void loadFromFile(const std::string &filename)
     {
          std::ifstream file(filename);
          std::string line;
          while (std::getline(file, line))
          {
               std::stringstream ss(line);
               std::string type, id, name, salary, teamSize;
               std::getline(ss, type, ',');
               std::getline(ss, id, ',');
               std::getline(ss, name, ',');
               std::getline(ss, salary, ',');
               if (type == "Manager")
               {
                    std::getline(ss, teamSize, ',');
                    addEmployee(std::make_unique<Manager>(name, std::stoi(id), std::stod(salary), std::stoi(teamSize)));
               }
               else
               {
                    addEmployee(std::make_unique<Employee>(name, std::stoi(id), std::stod(salary)));
               }
          }
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
          std::cout << "Input cannot be empty.\n";
     }
}

double getValidatedDouble(const std::string &prompt)
{
     double val;
     while (true)
     {
          std::cout << prompt;
          std::cin >> val;
          if (std::cin.fail() || val < 0)
          {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "Invalid input. Enter a positive number.\n";
          }
          else
          {
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               return val;
          }
     }
}

int getValidatedInt(const std::string &prompt)
{
     int val;
     while (true)
     {
          std::cout << prompt;
          std::cin >> val;
          if (std::cin.fail())
          {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "Invalid input. Enter an integer.\n";
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
     HR hr;
     // Add some initial employees
     hr.addEmployee(std::make_unique<Employee>("Alice", 1, 50000));
     hr.addEmployee(std::make_unique<Employee>("Bob", 2, 60000));
     int choice;
     while (true)
     {
          std::cout << "1. Add Employee\n2. Remove Employee\n3. List Employees\n4. Update Salary\n5. Total Employees\n6. Sort by Salary\n7. Search by Name\n8. Save to File\n9. Load from File\n10. Exit\nChoice: ";
          choice = getValidatedInt("");
          if (choice == 10)
               break;
          switch (choice)
          {
          case 1:
          {
               std::string name = getValidatedString("Name: ");
               int id = getValidatedInt("ID: ");
               double salary = getValidatedDouble("Salary: ");
               std::string type = getValidatedString("Type (Employee/Manager): ");
               if (type == "Manager")
               {
                    int teamSize = getValidatedInt("Team Size: ");
                    hr.addEmployee(std::make_unique<Manager>(name, id, salary, teamSize));
               }
               else
               {
                    hr.addEmployee(std::make_unique<Employee>(name, id, salary));
               }
               break;
          }
          case 2:
          {
               int id = getValidatedInt("ID to remove: ");
               hr.removeEmployee(id);
               break;
          }
          case 3:
               hr.listEmployees();
               break;
          case 4:
          {
               int id = getValidatedInt("ID: ");
               double salary = getValidatedDouble("New Salary: ");
               hr.updateSalary(id, salary);
               break;
          }
          case 5:
               std::cout << "Total employees: " << hr.totalEmployees() << std::endl;
               break;
          case 6:
               hr.sortEmployeesBySalary();
               std::cout << "Sorted by salary.\n";
               break;
          case 7:
          {
               std::string name = getValidatedString("Name to search: ");
               hr.searchEmployeeByName(name);
               break;
          }
          case 8:
               hr.saveToFile("employees.txt");
               std::cout << "Saved to file.\n";
               break;
          case 9:
               hr.loadFromFile("employees.txt");
               std::cout << "Loaded from file.\n";
               break;
          default:
               std::cout << "Invalid choice.\n";
          }
     }
     return 0;
}