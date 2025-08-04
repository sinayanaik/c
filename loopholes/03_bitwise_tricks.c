#include <stdio.h>

// TRICK: Check if number is power of 2 without loops
int is_power_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// TRICK: Count set bits using Brian Kernighan's algorithm
int count_set_bits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Clears the least significant set bit
        count++;
    }
    return count;
}

// TRICK: Swap without temp variable using XOR
void xor_swap(int *a, int *b) {
    if (a != b) {  // Important check to avoid self-swap
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

// TRICK: Check if number is even/odd using bitwise AND
int is_even(int n) {
    return !(n & 1);  // Returns 1 if even, 0 if odd
}

// TRICK: Get absolute value without branching
int abs_no_branch(int x) {
    int mask = x >> 31;  // Get sign bit (0 for positive, -1 for negative)
    return (x + mask) ^ mask;
}

// TRICK: Find minimum/maximum without branching
int min_no_branch(int x, int y) {
    return y ^ ((x ^ y) & -(x < y));
}

int max_no_branch(int x, int y) {
    return x ^ ((x ^ y) & -(x < y));
}

int main() {
    printf("=== Power of 2 Check ===\n");
    int numbers[] = {1, 2, 4, 8, 16, 3, 5, 7};
    for (int i = 0; i < 8; i++) {
        printf("%d is power of 2: %s\n", numbers[i], 
               is_power_of_two(numbers[i]) ? "YES" : "NO");
    }
    
    printf("\n=== Count Set Bits ===\n");
    for (int i = 0; i < 8; i++) {
        printf("Set bits in %d: %d\n", numbers[i], count_set_bits(numbers[i]));
    }
    
    printf("\n=== XOR Swap ===\n");
    int a = 5, b = 10;
    printf("Before: a=%d, b=%d\n", a, b);
    xor_swap(&a, &b);
    printf("After: a=%d, b=%d\n", a, b);
    
    printf("\n=== Even/Odd Check ===\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d is %s\n", i, is_even(i) ? "even" : "odd");
    }
    
    printf("\n=== Absolute Value ===\n");
    int neg_nums[] = {-5, -10, 15, -20};
    for (int i = 0; i < 4; i++) {
        printf("abs(%d) = %d\n", neg_nums[i], abs_no_branch(neg_nums[i]));
    }
    
    printf("\n=== Min/Max without branching ===\n");
    printf("min(5, 10) = %d\n", min_no_branch(5, 10));
    printf("max(5, 10) = %d\n", max_no_branch(5, 10));
    printf("min(15, 3) = %d\n", min_no_branch(15, 3));
    printf("max(15, 3) = %d\n", max_no_branch(15, 3));
    
    return 0;
} 