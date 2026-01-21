#include <iostream>
#include <vector>  

int main(void)
{
     int row = 0;
     int col = 0;
     std::cout << "how much verticle row:- ";
     std::cin >> row;
     std::cout << "how much horizontal column:- ";
     std::cin >> col;

     std::vector<std::vector<int>> matrix(row, std::vector<int>(col));
     
     std::cout << "\nEnter values for " << row << "x" << col << " matrix:\n";
     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < col; j++)
          {
               std::cout << "Element [" << i << "][" << j << "]: ";
               std::cin >> matrix[i][j];
          }
     }
     
     std::cout << "\nYour matrix:\n";
     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < col; j++)
          {
               std::cout << matrix[i][j] << "\t";
          }
          std::cout << std::endl;
     }
     
     int sum = 0;
     for (int i = 0; i < row; i++)
     {
          for (int j = 0; j < col; j++)
          {
               sum += matrix[i][j];
          }
     }
     std::cout << "\nSum of all elements: " << sum << std::endl;

     return 0;
}