#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
int main(void)
{
     char *name = get_string("what is your Name?  ");
     char *copy = malloc(strlen(name) + 1);
     for(int i = 0; i < strlen(name); i++){
          copy[i] =name[i];
     }
     copy[0] = toupper(*name);
     printf("name:- %s\n", name);
     printf("copy:- %s\n", copy);
}