#include<stdio.h>

void test();    //Function declaration (discussed in next topic)
 
int main()
{
    test();
    test();
    test();
}

void test()
{
    static int a = 0;       //a static variable
    a = a + 1;
    printf("%d\t",a);
}