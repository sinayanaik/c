#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers;  // ptr points to first element
    
    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }
    
    printf("\nArray elements using array notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    
    return 0;
} 