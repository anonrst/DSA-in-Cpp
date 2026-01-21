#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

class Grade
{
public:
     std::string subject;
     double score;
     double weight;
     Grade(std::string s, double sc, double w) : subject(s), score(sc), weight(w) {}
};

class Student
{
private:
     std::vector<Grade> grades;

public:
     void addGrade(const Grade &g)
     {
          grades.push_back(g);
     }
     double calculateWeightedAverage() const
     {
          double totalScore = 0.0;
          double totalWeight = 0.0;
          for (const auto &g : grades)
          {
               totalScore += g.score * g.weight;
               totalWeight += g.weight;
          }
          if (totalWeight == 0)
               return 0;
          return totalScore / totalWeight;
     }
     void displayGrades() const
     {
          for (const auto &g : grades)
          {
               std::cout << g.subject << ": " << g.score << " (weight: " << g.weight << ")" << std::endl;
          }
     }
};

double getValidatedDouble(const std::string &prompt, double min = 0, double max = 100)
{
     double val;
     while (true)
     {
          std::cout << prompt;
          std::cin >> val;
          if (std::cin.fail() || val < min || val > max)
          {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               std::cout << "Invalid input. Enter a number between " << min << " and " << max << "." << std::endl;
          }
          else
          {
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               return val;
          }
     }
}

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
     Student student;
     int numSubjects;
     std::cout << "Enter number of subjects: ";
     numSubjects = getValidatedDouble("", 1, 10); 
     for (int i = 0; i < numSubjects; ++i)
     {
          std::string subject = getValidatedString("Enter subject name: ");
          double score = getValidatedDouble("Enter score (0-100): ", 0, 100);
          double weight = getValidatedDouble("Enter weight (0-1): ", 0, 1);
          student.addGrade(Grade(subject, score, weight));
     }
     double avg = student.calculateWeightedAverage();
     std::cout << std::fixed << std::setprecision(2);
     std::cout << "Grades:" << std::endl;
     student.displayGrades();
     std::cout << "Weighted Average: " << avg << std::endl;
     if (avg >= 50)
     {
          std::cout << "Pass!" << std::endl;
     }
     else
     {
          std::cout << "Fail!" << std::endl;
     }
     return 0;
}