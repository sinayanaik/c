#include<stdio.h>

int number;     // global variable
int fun1();
int fun2();

void main()
{
    number = 10;
    printf("I am in main function. My value is %d\n", number);
    fun1();     //function calling, discussed in next topic
    fun2();     //function calling, discussed in next topic
}

/* This is function 1 */
int fun1()
{
    number = 200;
    printf("I am in function fun1. My value is %d", number);
}
/* This is function 1 */
int fun2()
{
    printf("\nI am in function fun2. My value is %d", number);
}