#include <stdio.h>

// INCORRECT: This doesn't work because parameters are local copies
void swap_incorrect(int a, int b) {
    printf("Inside swap_incorrect: a=%d, b=%d\n", a, b);
    
    // These operations only affect the local copies 'a' and 'b'
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    printf("After swap_incorrect: a=%d, b=%d\n", a, b);
    // The changes are lost when the function ends
}

// CORRECT: Using pointers to actually swap the original values
void swap_correct(int *a, int *b) {
    printf("Inside swap_correct: *a=%d, *b=%d\n", *a, *b);
    
    // XOR swap trick - works with pointers
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    
    printf("After swap_correct: *a=%d, *b=%d\n", *a, *b);
}

// ALTERNATIVE: Using temporary variable (more readable)
void swap_temp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5;
    int y = 10;
    
    printf("Before any swap: x=%d, y=%d\n", x, y);
    
    // This won't work - only local copies are swapped
    swap_incorrect(x, y);
    printf("After swap_incorrect: x=%d, y=%d\n", x, y);
    
    // This will work - actual values are swapped
    swap_correct(&x, &y);
    printf("After swap_correct: x=%d, y=%d\n", x, y);
    
    // Swap back using temp variable
    swap_temp(&x, &y);
    printf("After swap_temp: x=%d, y=%d\n", x, y);
    
    return 0;
} 