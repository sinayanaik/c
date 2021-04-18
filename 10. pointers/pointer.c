#include <stdio.h>

void main()
{
    int var = 7;
    printf("Value of the variable var is: %d\n", *&var);
    printf("Memory address of the variable var is: %x\n", &var);
}