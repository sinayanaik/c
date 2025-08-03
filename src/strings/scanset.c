#include <stdio.h>
int main()
{

    char string[100];
    printf("string: ");
    scanf("%[^\n]*%c",string);  //first %
                                //then [^\n] until null character is approached
                                //then *
                                //then %c

    printf("string: %s",string);

    
}