#include <stdio.h>

int main() {
    int number = 25;
    int* ptr = &number;
    
    printf("number = %d\n", number);
    printf("*ptr = %d\n", *ptr);
    
    // Modify value through pointer
    *ptr = 50;
    printf("After *ptr = 50:\n");
    printf("number = %d\n", number);
    printf("*ptr = %d\n", *ptr);
    
    return 0;
} 