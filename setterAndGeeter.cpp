#include <iostream>
class airConditionerTemp
{
private:
     int value = 0;

public:
     int getValue(void)
     {
          return value;
     }
     void setValue(int value)
     {
          if (value < 0)
          {
               this->value = 1;
          }
          else if (value >= 10)
          {
               this->value = 10;
          }
          else
          {
               this->value = value;
          }
     };
};
int main(void)
{
     airConditionerTemp A1;
     A1.setValue(4);
     std::cout << "the T value is:- " << A1.getValue() << '\n';
     return 0;
}