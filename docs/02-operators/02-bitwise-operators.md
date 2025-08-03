# Bitwise Operators in C

## Overview

Bitwise operators perform manipulations of data at the **bit level**. These operators also perform shifting of bits from right to left.

**Important**: Bitwise operators are **not applied to float or double** data types.

## Bitwise Operators Table

| Operator | Description | Example |
|----------|-------------|---------|
| `&` | Bitwise AND | `a & b` |
| `\|` | Bitwise OR | `a \| b` |
| `^` | Bitwise XOR | `a ^ b` |
| `<<` | Left shift | `a << b` |
| `>>` | Right shift | `a >> b` |
| `~` | Bitwise NOT | `~a` |

## Detailed Explanation

### 1. Bitwise AND (`&`)

The `&` operator takes two numbers as operands and does AND on every bit of two numbers. The result of AND is **1 only if both bits are 1**.

**Truth Table:**
| A | B | A & B |
|---|---|-------|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

```c
#include<stdio.h>

int main() {
    int a = 5;  // 0101 in binary
    int b = 3;  // 0011 in binary
    
    int result = a & b;  // 0001 = 1 in decimal
    printf("%d & %d = %d\n", a, b, result);
    
    return 0;
}
```

### 2. Bitwise OR (`|`)

The `|` operator takes two numbers as operands and does OR on every bit of two numbers. The result of OR is **1 if any of the two bits is 1**.

**Truth Table:**
| A | B | A \| B |
|---|---|--------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

```c
#include<stdio.h>

int main() {
    int a = 5;  // 0101 in binary
    int b = 3;  // 0011 in binary
    
    int result = a | b;  // 0111 = 7 in decimal
    printf("%d | %d = %d\n", a, b, result);
    
    return 0;
}
```

### 3. Bitwise XOR (`^`)

The `^` operator takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is **1 if the two bits are different**.

**Truth Table:**
| A | B | A ^ B |
|---|---|-------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

```c
#include<stdio.h>

int main() {
    int a = 5;  // 0101 in binary
    int b = 3;  // 0011 in binary
    
    int result = a ^ b;  // 0110 = 6 in decimal
    printf("%d ^ %d = %d\n", a, b, result);
    
    return 0;
}
```

### 4. Left Shift (`<<`)

The `<<` operator takes two numbers, left shifts the bits of the first operand, and the second operand decides the number of places to shift.

**Formula**: `a << b` = `a * (2^b)`

```c
#include<stdio.h>

int main() {
    int a = 5;  // 0101 in binary
    
    int result1 = a << 1;  // 1010 = 10 in decimal
    int result2 = a << 2;  // 10100 = 20 in decimal
    int result3 = a << 3;  // 101000 = 40 in decimal
    
    printf("%d << 1 = %d\n", a, result1);
    printf("%d << 2 = %d\n", a, result2);
    printf("%d << 3 = %d\n", a, result3);
    
    return 0;
}
```

### 5. Right Shift (`>>`)

The `>>` operator takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift.

**Formula**: `a >> b` = `a / (2^b)` (integer division)

```c
#include<stdio.h>

int main() {
    int a = 20;  // 10100 in binary
    
    int result1 = a >> 1;  // 1010 = 10 in decimal
    int result2 = a >> 2;  // 101 = 5 in decimal
    int result3 = a >> 3;  // 10 = 2 in decimal
    
    printf("%d >> 1 = %d\n", a, result1);
    printf("%d >> 2 = %d\n", a, result2);
    printf("%d >> 3 = %d\n", a, result3);
    
    return 0;
}
```

### 6. Bitwise NOT (`~`)

The `~` operator takes one number and **inverts all bits** of it.

```c
#include<stdio.h>

int main() {
    int a = 5;  // 0101 in binary
    
    int result = ~a;  // 1010...1010 (all bits inverted)
    printf("~%d = %d\n", a, result);
    
    return 0;
}
```

## Practical Examples

### 1. Setting and Clearing Bits

```c
#include<stdio.h>

int main() {
    int num = 10;  // 1010 in binary
    
    // Set bit at position 2 (0-based)
    int set_bit = num | (1 << 2);  // 1110 = 14
    printf("After setting bit 2: %d\n", set_bit);
    
    // Clear bit at position 1 (0-based)
    int clear_bit = num & ~(1 << 1);  // 1000 = 8
    printf("After clearing bit 1: %d\n", clear_bit);
    
    // Toggle bit at position 0 (0-based)
    int toggle_bit = num ^ (1 << 0);  // 1011 = 11
    printf("After toggling bit 0: %d\n", toggle_bit);
    
    return 0;
}
```

### 2. Checking Bit Status

```c
#include<stdio.h>

int main() {
    int num = 10;  // 1010 in binary
    
    // Check if bit at position 1 is set
    if (num & (1 << 1)) {
        printf("Bit 1 is set\n");
    } else {
        printf("Bit 1 is not set\n");
    }
    
    // Check if bit at position 2 is set
    if (num & (1 << 2)) {
        printf("Bit 2 is set\n");
    } else {
        printf("Bit 2 is not set\n");
    }
    
    return 0;
}
```

### 3. Counting Set Bits

```c
#include<stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;  // Add 1 if last bit is set
        n >>= 1;         // Right shift by 1
    }
    return count;
}

int main() {
    int num = 15;  // 1111 in binary
    printf("Number of set bits in %d: %d\n", num, countSetBits(num));
    
    return 0;
}
```

### 4. Power of 2 Check

```c
#include<stdio.h>

int isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int numbers[] = {1, 2, 4, 8, 16, 3, 5, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    for (int i = 0; i < size; i++) {
        printf("%d is %s power of 2\n", 
               numbers[i], 
               isPowerOfTwo(numbers[i]) ? "a" : "not a");
    }
    
    return 0;
}
```

## Common Use Cases

### 1. Flags and Masks
```c
#define FLAG_READ     (1 << 0)  // 0001
#define FLAG_WRITE    (1 << 1)  // 0010
#define FLAG_EXECUTE  (1 << 2)  // 0100

int permissions = FLAG_READ | FLAG_WRITE;  // 0011
```

### 2. Efficient Multiplication/Division
```c
int multiplyByTwo(int x) {
    return x << 1;  // x * 2
}

int divideByTwo(int x) {
    return x >> 1;  // x / 2
}
```

### 3. Swapping Without Temp Variable
```c
void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
```

## Best Practices

1. **Use parentheses** for complex bitwise expressions
2. **Be careful with signed integers** - right shift behavior may vary
3. **Use unsigned integers** for bit manipulation when possible
4. **Document bit positions** clearly (0-based or 1-based)
5. **Test edge cases** - zero, negative numbers, large numbers

## Common Pitfalls

### 1. Operator Precedence
```c
// Wrong
int result = a & b == 0;  // Evaluates as a & (b == 0)

// Correct
int result = (a & b) == 0;
```

### 2. Signed vs Unsigned
```c
int signed_num = -1;
unsigned int unsigned_num = -1;

printf("Signed: %d\n", signed_num >> 1);    // Implementation defined
printf("Unsigned: %u\n", unsigned_num >> 1); // Well defined
```

### 3. Overflow in Shifts
```c
int num = 1;
int result = num << 32;  // Undefined behavior if int is 32 bits
``` 