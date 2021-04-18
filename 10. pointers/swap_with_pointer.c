#include <stdio.h>
void swap(int *a,int *b);
int main()
{
    int x,y;

    printf("x: ");
    scanf("%d",&x);

    printf("y: ");
    scanf("%d",&y);

    swap(&x,&y);

    printf("before swap \nx = %d\ny = %d\n",x,y);



}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}