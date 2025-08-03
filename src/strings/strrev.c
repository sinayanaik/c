#include <stdio.h>
#include <string.h>
int main()
{
    char string[30];
    printf("String: ");
    scanf("%[^\n]*%c",string);

    

    printf("strrev(%s) = %s\n",string,strrev(string));
}