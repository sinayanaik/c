#include <stdio.h>
#include <string.h>
int main()
{
    
    printf("strcmp(\"A\",\"B\") = %d\n",strcmp("A","B")); //-1 lower to higher
    printf("strcmp(\"B\",\"A\") = %d\n",strcmp("B","A")); // 1 higher to lower

}