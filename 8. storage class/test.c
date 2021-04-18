#include <stdio.h>
int double;
int main()
{
    static int x =10;
    printf("x = %d\n",x);
    double();
    printf("x = %d\n",x);
}
int double(int x)
{
 x=x+x;
}