#include <stdio.h>
#include <stdlib.h>

int main() {
    int value = 100;
    int* ptr1 = &value;
    int** ptr2 = &ptr1;  // Pointer to pointer
    
    printf("value = %d\n", value);
    printf("*ptr1 = %d\n", *ptr1);
    printf("**ptr2 = %d\n", **ptr2);
    
    printf("\nAddresses:\n");
    printf("&value = %p\n", (void*)&value);
    printf("ptr1 = %p\n", (void*)ptr1);
    printf("&ptr1 = %p\n", (void*)&ptr1);
    printf("ptr2 = %p\n", (void*)ptr2);
    
    // Modify value through double pointer
    **ptr2 = 200;
    printf("\nAfter **ptr2 = 200:\n");
    printf("value = %d\n", value);
    
    return 0;
} 