// C program to demonstrate working
// of logical NOT '!' operators
  
#include <stdio.h>
  
int main()
{
  
    // Taking a variable a
    // and set it to 0 (false)
    int a = 0;
  
    // logical NOT example
  
    // Since 0 is considered to be false
    // !a will yield true
    if (!a)
        printf("Condition yielded True\n");
    else
        printf("Condition yielded False\n");
  
    // set a to non-zero value (true)
    a = 1;
  
    // Since a non-zero value is considered to be true
    // !a will yield false
    if (!a)
        printf("Condition yielded True\n");
    else
        printf("Condition yielded False\n");
  
    return 0;
}