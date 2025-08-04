#include <stdio.h>

int main() {
    int number = 42;
    int* pointer = &number;  // pointer stores address of number
    
    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", (void*)&number);
    printf("Value of pointer: %p\n", (void*)pointer);
    printf("Value pointed by pointer: %d\n", *pointer);
    
    return 0;
} 