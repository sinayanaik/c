#include <stdio.h>

int main() {
    // Different ways to declare pointers
    int* ptr1;     // Pointer to int
    int *ptr2;     // Alternative syntax
    int * ptr3;    // Another alternative
    
    // Initialize pointers
    int number = 100;
    int* ptr = &number;  // ptr points to number
    
    printf("number = %d\n", number);
    printf("&number = %p\n", (void*)&number);
    printf("ptr = %p\n", (void*)ptr);
    printf("*ptr = %d\n", *ptr);
    
    return 0;
} 