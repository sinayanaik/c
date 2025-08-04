#include <stdio.h>

// TRICK: Operator precedence can lead to unexpected results
void precedence_tricks() {
    int a = 5, b = 10, c = 15;
    
    printf("=== Operator Precedence Tricks ===\n");
    
    // TRICK: Unclear precedence
    int result1 = a + b * c;
    printf("a + b * c = %d (not %d)\n", result1, (a + b) * c);
    
    // TRICK: Bitwise operators have lower precedence than arithmetic
    int result2 = a & b + c;
    printf("a & b + c = %d (not %d)\n", result2, (a & b) + c);
    
    // TRICK: Assignment has very low precedence
    int x = 1, y = 2;
    int result3 = x = y = 5;  // Assignment is right-associative
    printf("x = y = 5: x=%d, y=%d, result=%d\n", x, y, result3);
    
    // TRICK: Comma operator has lowest precedence
    int result4 = (a = 10, b = 20, a + b);
    printf("(a = 10, b = 20, a + b) = %d\n", result4);
}

// TRICK: Short-circuit evaluation tricks
void short_circuit_tricks() {
    printf("\n=== Short-Circuit Evaluation ===\n");
    
    int a = 0, b = 5;
    
    // TRICK: Side effects in logical expressions
    if (a && b++) {
        printf("This won't execute\n");
    }
    printf("After a && b++: b = %d\n", b);  // b is still 5
    
    if (a || b++) {
        printf("This will execute\n");
    }
    printf("After a || b++: b = %d\n", b);  // b is still 5 (short-circuited)
    
    // TRICK: Using short-circuit for conditional execution
    int x = 10;
    (x > 5) && printf("x is greater than 5\n");
    (x < 5) && printf("This won't print\n");
}

// TRICK: Type conversion surprises
void type_conversion_tricks() {
    printf("\n=== Type Conversion Tricks ===\n");
    
    // TRICK: Integer division
    int a = 5, b = 2;
    float result1 = a / b;
    printf("5 / 2 = %f (integer division!)\n", result1);
    
    float result2 = (float)a / b;
    printf("(float)5 / 2 = %f\n", result2);
    
    // TRICK: Character arithmetic
    char c = 'A';
    printf("'A' + 1 = %c\n", c + 1);
    printf("'A' + 1 = %d\n", c + 1);
    
    // TRICK: Integer overflow
    int max_int = 2147483647;
    printf("max_int = %d\n", max_int);
    printf("max_int + 1 = %d (overflow!)\n", max_int + 1);
}

// TRICK: Pointer arithmetic surprises
void pointer_tricks() {
    printf("\n=== Pointer Arithmetic Tricks ===\n");
    
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    printf("arr[0] = %d\n", *ptr);
    printf("arr[1] = %d\n", *(ptr + 1));
    printf("arr[2] = %d\n", *(ptr + 2));
    
    // TRICK: Pointer arithmetic with different types
    char *char_ptr = (char*)arr;
    printf("char_ptr + 1 = %p\n", (void*)(char_ptr + 1));
    printf("ptr + 1 = %p\n", (void*)(ptr + 1));
    
    // TRICK: Array indexing with pointers
    printf("ptr[0] = %d\n", ptr[0]);
    printf("0[ptr] = %d (same as ptr[0]!)\n", 0[ptr]);
}

int main() {
    precedence_tricks();
    short_circuit_tricks();
    type_conversion_tricks();
    pointer_tricks();
    
    return 0;
} 