#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    
    printf("Using pointer increment:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr++;  // Move to next element
    }
    printf("\n");
    
    // Reset pointer
    ptr = arr;
    
    printf("Using pointer decrement (reverse):\n");
    ptr = &arr[4];  // Point to last element
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr--;  // Move to previous element
    }
    printf("\n");
    
    return 0;
} 