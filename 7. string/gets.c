#include <stdio.h>
int main()
{
    char text[100];
    printf("text: ");
    gets(text);
    printf("text: %s", text);
}