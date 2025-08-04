# Pointer Basics in C Programming

## Overview

Pointers are variables that store memory addresses of other variables. They are one of the most powerful and fundamental concepts in C programming, allowing direct memory manipulation and efficient data access.

## What is a Pointer?

### Basic Concept

```c
#include <stdio.h>

int main() {
    int number = 42;
    int* pointer = &number;  // pointer stores address of number
    
    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", (void*)&number);
    printf("Value of pointer: %p\n", (void*)pointer);
    printf("Value pointed by pointer: %d\n", *pointer);
    
    return 0;
}
```

**Output:**
```
Value of number: 42
Address of number: 0x7ffe81ba94dc
Value of pointer: 0x7ffe81ba94dc
Value pointed by pointer: 42
```

### Pointer Declaration

```c
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
```

**Output:**
```
number = 100
&number = 0x7fff012227cc
ptr = 0x7fff012227cc
*ptr = 100
```

## Pointer Operators

### 1. **Address Operator (&)**

```c
#include <stdio.h>

int main() {
    int x = 10;
    float y = 3.14;
    char ch = 'A';
    
    printf("Address of x: %p\n", (void*)&x);
    printf("Address of y: %p\n", (void*)&y);
    printf("Address of ch: %p\n", (void*)&ch);
    
    // Store addresses in pointers
    int* ptr_x = &x;
    float* ptr_y = &y;
    char* ptr_ch = &ch;
    
    printf("ptr_x = %p\n", (void*)ptr_x);
    printf("ptr_y = %p\n", (void*)ptr_y);
    printf("ptr_ch = %p\n", (void*)ptr_ch);
    
    return 0;
}
```

**Output:**
```
Address of x: 0x7fffd02ba0a8
Address of y: 0x7fffd02ba0ac
Address of ch: 0x7fffd02ba0a7
ptr_x = 0x7fffd02ba0a8
ptr_y = 0x7fffd02ba0ac
ptr_ch = 0x7fffd02ba0a7
```

### 2. **Dereference Operator (*)**

```c
#include <stdio.h>

int main() {
    int number = 25;
    int* ptr = &number;
    
    printf("number = %d\n", number);
    printf("*ptr = %d\n", *ptr);
    
    // Modify value through pointer
    *ptr = 50;
    printf("After *ptr = 50:\n");
    printf("number = %d\n", number);
    printf("*ptr = %d\n", *ptr);
    
    return 0;
}
```

**Output:**
```
number = 25
*ptr = 25
After *ptr = 50:
number = 50
*ptr = 50
```

## Pointer Arithmetic

### Basic Pointer Arithmetic

```c
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
```

**Output:**
```
Array elements using pointer arithmetic:
*(ptr + 0) = 10
*(ptr + 1) = 20
*(ptr + 2) = 30
*(ptr + 3) = 40
*(ptr + 4) = 50

Array elements using array notation:
ptr[0] = 10
ptr[1] = 20
ptr[2] = 30
ptr[3] = 40
ptr[4] = 50
```

### Pointer Increment/Decrement

```c
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
```

**Output:**
```
Using pointer increment:
1 2 3 4 5 
Using pointer decrement (reverse):
5 4 3 2 1 
```

## Pointers and Arrays

### Array-Pointer Relationship

```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    printf("Array name as pointer:\n");
    printf("arr = %p\n", (void*)arr);
    printf("&arr[0] = %p\n", (void*)&arr[0]);
    printf("arr == &arr[0]: %s\n\n", arr == &arr[0] ? "True" : "False");
    
    printf("Accessing elements:\n");
    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("*(&arr[0] + 2) = %d\n", *(arr + 2));
    
    return 0;
}
```

**Output:**
```
Array name as pointer:
arr = 0x7ffce5a22de0
&arr[0] = 0x7ffce5a22de0
arr == &arr[0]: True

Accessing elements:
arr[2] = 30
*(arr + 2) = 30
*(&arr[0] + 2) = 30
```

### Passing Arrays to Functions

```c
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
```

**Output:**
```
Original array: 1 2 3 4 5 
Modified array: 2 4 6 8 10 
```

## Null Pointers

### Understanding Null Pointers

```c
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
```

**Output:**
```
ptr = (nil)
Pointer is null
Cannot dereference null pointer
```

### Common Null Pointer Usage

```c
#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    if (size <= 0) {
        return NULL;  // Return null for invalid size
    }
    
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        return NULL;  // Return null if allocation fails
    }
    
    // Initialize array
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    
    return arr;
}

int main() {
    int* arr = createArray(5);
    
    if (arr != NULL) {
        printf("Array created successfully:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        free(arr);  // Don't forget to free
    } else {
        printf("Failed to create array\n");
    }
    
    return 0;
}
```

## Void Pointers

### Generic Pointers

```c
#include <stdio.h>

void printValue(void* ptr, char type) {
    switch (type) {
        case 'i':
            printf("Integer: %d\n", *(int*)ptr);
            break;
        case 'f':
            printf("Float: %f\n", *(float*)ptr);
            break;
        case 'c':
            printf("Char: %c\n", *(char*)ptr);
            break;
        default:
            printf("Unknown type\n");
    }
}

int main() {
    int i = 42;
    float f = 3.14;
    char c = 'A';
    
    printValue(&i, 'i');
    printValue(&f, 'f');
    printValue(&c, 'c');
    
    return 0;
}
```

**Output:**
```
Integer: 42
Float: 3.140000
Char: A
```

### Memory Operations with Void Pointers

```c
#include <stdio.h>
#include <string.h>

void* copyMemory(void* dest, const void* src, size_t size) {
    return memcpy(dest, src, size);
}

int main() {
    int source[] = {1, 2, 3, 4, 5};
    int dest[5];
    
    // Copy using void pointer
    copyMemory(dest, source, sizeof(source));
    
    printf("Copied array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Pointers to Pointers

### Double Pointers

```c
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
```

**Output:**
```
value = 100
*ptr1 = 100
**ptr2 = 100

Addresses:
&value = 0x7ffd993df114
ptr1 = 0x7ffd993df114
&ptr1 = 0x7ffd993df118
ptr2 = 0x7ffd993df118

After **ptr2 = 200:
value = 200
```

### Dynamic Allocation with Double Pointers

```c
#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols) {
    int** matrix = malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows = 3, cols = 4;
    int** matrix = createMatrix(rows, cols);
    
    if (matrix != NULL) {
        // Initialize matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = i * cols + j;
            }
        }
        
        // Print matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        
        freeMatrix(matrix, rows);
    } else {
        printf("Failed to create matrix\n");
    }
    
    return 0;
}
```

## Function Pointers

### Basic Function Pointers

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return b != 0 ? a / b : 0;
}

int main() {
    // Function pointer declaration
    int (*operation)(int, int);
    
    int x = 10, y = 5;
    
    // Use function pointer
    operation = add;
    printf("%d + %d = %d\n", x, y, operation(x, y));
    
    operation = subtract;
    printf("%d - %d = %d\n", x, y, operation(x, y));
    
    operation = multiply;
    printf("%d * %d = %d\n", x, y, operation(x, y));
    
    operation = divide;
    printf("%d / %d = %d\n", x, y, operation(x, y));
    
    return 0;
}
```

**Output:**
```
10 + 5 = 15
10 - 5 = 5
10 * 5 = 50
10 / 5 = 2
```

### Array of Function Pointers

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    // Array of function pointers
    int (*operations[])(int, int) = {add, subtract, multiply, divide};
    char* names[] = {"add", "subtract", "multiply", "divide"};
    
    int x = 20, y = 4;
    
    for (int i = 0; i < 4; i++) {
        printf("%s(%d, %d) = %d\n", names[i], x, y, operations[i](x, y));
    }
    
    return 0;
}
```

## Common Pointer Patterns

### 1. **Swapping Values**

```c
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    
    return 0;
}
```

**Output:**
```
Before swap: x = 10, y = 20
After swap: x = 20, y = 10
```

### 2. **Returning Multiple Values**

```c
#include <stdio.h>
#include <math.h>

void calculateCircle(double radius, double* area, double* circumference) {
    *area = M_PI * radius * radius;
    *circumference = 2 * M_PI * radius;
}

int main() {
    double radius = 5.0;
    double area, circumference;
    
    calculateCircle(radius, &area, &circumference);
    
    printf("Radius: %.2f\n", radius);
    printf("Area: %.2f\n", area);
    printf("Circumference: %.2f\n", circumference);
    
    return 0;
}
```

### 3. **Dynamic Arrays**

```c
#include <stdio.h>
#include <stdlib.h>

int* createDynamicArray(int size) {
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }
    
    // Initialize array
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }
    
    return arr;
}

int* resizeArray(int* arr, int oldSize, int newSize) {
    int* newArr = realloc(arr, newSize * sizeof(int));
    if (newArr == NULL) {
        return arr;  // Return original if realloc fails
    }
    
    // Initialize new elements
    for (int i = oldSize; i < newSize; i++) {
        newArr[i] = 0;
    }
    
    return newArr;
}

int main() {
    int* arr = createDynamicArray(5);
    
    if (arr != NULL) {
        printf("Original array: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        // Resize array
        arr = resizeArray(arr, 5, 8);
        
        printf("Resized array: ");
        for (int i = 0; i < 8; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        
        free(arr);
    }
    
    return 0;
}
```

## Best Practices

### 1. **Always Initialize Pointers**

```c
// Good: Initialize pointer
int* ptr = NULL;

// Bad: Uninitialized pointer
int* ptr;  // Contains garbage address
```

### 2. **Check for NULL Before Dereferencing**

```c
// Good: Check for null
if (ptr != NULL) {
    printf("Value: %d\n", *ptr);
}

// Bad: No null check
printf("Value: %d\n", *ptr);  // May crash
```

### 3. **Use const for Read-Only Pointers**

```c
// Good: Use const for read-only access
void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

// Bad: No const protection
void printArray(int* arr, int size) {
    // Could accidentally modify array
}
```

## Common Mistakes

### 1. **Dangling Pointers**

```c
#include <stdio.h>

int* createValue() {
    int x = 10;
    return &x;  // DANGEROUS: x goes out of scope
}

int main() {
    int* ptr = createValue();
    printf("%d\n", *ptr);  // Undefined behavior
    return 0;
}
```

### 2. **Memory Leaks**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = malloc(sizeof(int));
    *ptr = 100;
    
    // Use ptr
    printf("Value: %d\n", *ptr);
    
    // Forget to free
    // free(ptr);  // Memory leak!
    
    return 0;
}
```

### 3. **Buffer Overflow**

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    
    // Access beyond array bounds
    printf("%d\n", ptr[10]);  // Undefined behavior
    
    return 0;
}
```

## Summary

**Key Points:**
- Pointers store memory addresses
- Use & to get address, * to dereference
- Pointers enable dynamic memory allocation
- Always check for NULL before dereferencing
- Use const for read-only access

**Best Practices:**
- Initialize pointers to NULL
- Check for null before dereferencing
- Use const for read-only pointers
- Free dynamically allocated memory
- Avoid dangling pointers

**Common Use Cases:**
- Dynamic memory allocation
- Array manipulation
- Function parameters
- Data structures
- System programming 