#include <stdio.h>

int main() {
    int* ptr = NULL;  // Null pointer
    
    printf("ptr = %p\n", (void*)ptr);
    
    // Check for null pointer
    if (ptr == NULL) {
        printf("Pointer is null\n");
    } else {
        printf("Pointer is not null\n");
    }
    
    // Safe way to use pointer
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
    } else {
        printf("Cannot dereference null pointer\n");
    }
    
    return 0;
} 