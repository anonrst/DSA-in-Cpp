#include <iostream>

typedef struct node
{
     int number;
     struct node *leftnext;
     struct node *rightnext;
} node;
int main(void)
{

     return 0;
}

bool search(node *bst, int number)
{
     if (bst == nullptr)
     {
          return 1;
     }
     else if (number < bst->number)
     {
          search(bst->leftnext, number);
     }
     else if (number > bst->number)
     {
          search(bst->rightnext, number);
     }
     else
     {
          return true;
     }
}