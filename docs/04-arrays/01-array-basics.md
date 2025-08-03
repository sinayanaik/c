# Array Basics in C Programming

## Overview

An array is a collection of elements of the same data type stored in contiguous memory locations. Arrays provide an efficient way to store and access multiple values using a single variable name.

## Array Declaration

### Basic Syntax

```c
data_type array_name[size];
```

### Examples

```c
int numbers[10];           // Array of 10 integers
char letters[26];          // Array of 26 characters
float prices[5];           // Array of 5 floating-point numbers
double measurements[100];   // Array of 100 double-precision numbers
```

## Array Initialization

### 1. **Declaration with Initialization**

```c
#include <stdio.h>

int main() {
    // Initialize with values
    int numbers[5] = {1, 2, 3, 4, 5};
    
    // Initialize with fewer values (rest are zero)
    int scores[10] = {85, 92, 78, 96};
    
    // Initialize all to zero
    int zeros[5] = {0};
    
    // Let compiler determine size
    int auto_size[] = {10, 20, 30, 40, 50};
    
    return 0;
}
```

### 2. **Partial Initialization**

```c
#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3};  // First 3 elements initialized, rest are 0
    
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}
```

### 3. **Designated Initializers (C99)**

```c
#include <stdio.h>

int main() {
    // Initialize specific elements
    int arr[10] = {[0] = 1, [5] = 25, [9] = 100};
    
    // Initialize range
    int range[10] = {[0 ... 4] = 1, [5 ... 9] = 2};
    
    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}
```

## Accessing Array Elements

### Index-Based Access

```c
#include <stdio.h>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    
    // Access individual elements
    printf("First element: %d\n", numbers[0]);
    printf("Third element: %d\n", numbers[2]);
    printf("Last element: %d\n", numbers[4]);
    
    // Modify elements
    numbers[1] = 25;
    numbers[3] = 45;
    
    // Print all elements
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    
    return 0;
}
```

## Array Operations

### 1. **Finding Array Size**

```c
#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Calculate size using sizeof
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("Array size: %d\n", size);
    
    return 0;
}
```

### 2. **Copying Arrays**

```c
#include <stdio.h>

int main() {
    int source[] = {1, 2, 3, 4, 5};
    int destination[5];
    int size = sizeof(source) / sizeof(source[0]);
    
    // Copy array elements
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
    
    // Verify copy
    for (int i = 0; i < size; i++) {
        printf("destination[%d] = %d\n", i, destination[i]);
    }
    
    return 0;
}
```

### 3. **Finding Maximum and Minimum**

```c
#include <stdio.h>

int main() {
    int numbers[] = {23, 45, 12, 67, 34, 89, 56, 78};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int max = numbers[0];
    int min = numbers[0];
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    
    return 0;
}
```

### 4. **Sum and Average**

```c
#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    
    float average = (float)sum / size;
    
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    
    return 0;
}
```

## Array Bounds

### Bounds Checking

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Valid access
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[4] = %d\n", arr[4]);
    
    // Invalid access (undefined behavior)
    printf("arr[5] = %d\n", arr[5]);  // Out of bounds
    printf("arr[-1] = %d\n", arr[-1]); // Out of bounds
    
    return 0;
}
```

### Safe Array Access

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int index;
    printf("Enter index (0-%d): ", size - 1);
    scanf("%d", &index);
    
    if (index >= 0 && index < size) {
        printf("arr[%d] = %d\n", index, arr[index]);
    } else {
        printf("Index out of bounds\n");
    }
    
    return 0;
}
```

## Character Arrays (Strings)

### String Declaration

```c
#include <stdio.h>

int main() {
    // Character array
    char str1[10] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    // String literal
    char str2[] = "Hello";
    
    // Fixed size string
    char str3[20] = "Hello World";
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    
    return 0;
}
```

### String Operations

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[50] = "Hello";
    
    // String length
    printf("Length: %zu\n", strlen(str));
    
    // String copy
    char dest[50];
    strcpy(dest, str);
    printf("Copied: %s\n", dest);
    
    // String concatenation
    strcat(str, " World");
    printf("Concatenated: %s\n", str);
    
    return 0;
}
```

## Multi-dimensional Arrays

### 2D Arrays

```c
#include <stdio.h>

int main() {
    // Declaration
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Access elements
    printf("matrix[1][2] = %d\n", matrix[1][2]);
    
    // Print matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

### 3D Arrays

```c
#include <stdio.h>

int main() {
    int cube[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };
    
    // Access element
    printf("cube[1][2][3] = %d\n", cube[1][2][3]);
    
    return 0;
}
```

## Array as Function Parameters

### Passing Arrays to Functions

```c
#include <stdio.h>

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to modify array
void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Double each element
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    printArray(numbers, size);
    
    modifyArray(numbers, size);
    
    printf("Modified array: ");
    printArray(numbers, size);
    
    return 0;
}
```

## Common Array Algorithms

### 1. **Linear Search**

```c
#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Found at index i
        }
    }
    return -1;  // Not found
}

int main() {
    int numbers[] = {10, 25, 30, 45, 50, 60};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 45;
    
    int result = linearSearch(numbers, size, target);
    
    if (result != -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("%d not found\n", target);
    }
    
    return 0;
}
```

### 2. **Bubble Sort**

```c
#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    printArray(numbers, size);
    
    bubbleSort(numbers, size);
    
    printf("Sorted array: ");
    printArray(numbers, size);
    
    return 0;
}
```

## Best Practices

### 1. **Always Check Bounds**

```c
// Good: Check bounds before access
if (index >= 0 && index < size) {
    value = array[index];
} else {
    // Handle error
}

// Bad: No bounds checking
value = array[index];  // May cause undefined behavior
```

### 2. **Use sizeof for Array Size**

```c
// Good: Use sizeof for size
int size = sizeof(array) / sizeof(array[0]);

// Bad: Hard-coded size
int size = 10;  // May not match actual array size
```

### 3. **Initialize Arrays**

```c
// Good: Initialize arrays
int numbers[5] = {0};  // All elements initialized to 0

// Bad: Uninitialized array
int numbers[5];  // Contains garbage values
```

## Common Mistakes

### 1. **Array Bounds Overflow**

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Wrong: Accessing beyond array bounds
    for (int i = 0; i <= 5; i++) {  // Should be < 5
        printf("%d ", arr[i]);
    }
    
    return 0;
}
```

### 2. **Forgetting Null Terminator**

```c
#include <stdio.h>

int main() {
    char str[5] = {'H', 'e', 'l', 'l', 'o'};  // Missing '\0'
    
    printf("%s\n", str);  // Undefined behavior
    
    return 0;
}
```

### 3. **Array Assignment**

```c
#include <stdio.h>

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5];
    
    // Wrong: Cannot assign arrays directly
    // arr2 = arr1;  // Compilation error
    
    // Correct: Copy elements
    for (int i = 0; i < 5; i++) {
        arr2[i] = arr1[i];
    }
    
    return 0;
}
```

## Summary

**Key Points:**
- Arrays store elements of the same type in contiguous memory
- Array indices start from 0
- Arrays are passed by reference to functions
- Always check array bounds to avoid undefined behavior
- Use sizeof to determine array size

**Best Practices:**
- Initialize arrays when declaring them
- Check bounds before accessing elements
- Use meaningful array names
- Consider using constants for array sizes
- Handle array operations safely

**Common Use Cases:**
- Storing collections of data
- Implementing algorithms
- Working with strings
- Multi-dimensional data representation
- Function parameter passing 