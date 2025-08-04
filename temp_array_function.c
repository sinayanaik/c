#include <stdio.h>

// Function that takes array as pointer
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function that modifies array through pointer
void doubleArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modify original array
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    printArray(numbers, size);
    
    doubleArray(numbers, size);
    
    printf("Modified array: ");
    printArray(numbers, size);
    
    return 0;
} 