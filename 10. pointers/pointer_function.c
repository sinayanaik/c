#include <stdio.h>
int *larger(int *a,int *b);
int main()
{
    int x,y;

    printf("x: ");
    scanf("%d",&x);

    printf("y: ");
    scanf("%d",&y);

    printf("larger: %d\n",*larger(&x,&y));  //get what things are in the addresses


}

int *larger(int *a,int *b)     // a and b are pointers to integers
                               //they are just address
{
    if(*a>*b)                 /*we dont want to compare the addresses but the contents of the addresses*/ 
    return a;                 //return the addresses
    else
    return b;
}