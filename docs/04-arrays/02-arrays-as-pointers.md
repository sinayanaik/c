# Arrays as Pointers in C

## Overview

In C, arrays and pointers are closely related. An array name can be used as a pointer to the first element of the array. This relationship is fundamental to understanding how arrays work in C.

## Basic Concept

When you declare an array:

```c
int arr[5] = {1, 2, 3, 4, 5};
```

The array name `arr` has **two purposes**:

1. **It is the name of the array**
2. **It acts as a pointer pointing towards the first element in the array**

## Key Relationship

```c
arr == &arr[0]  // By default
```

This means the array name `arr` is equivalent to the address of the first element `&arr[0]`.

## Memory Layout

```
Memory Address:  1000  1004  1008  1012  1016
Array Index:       0     1     2     3     4
Array Value:       1     2     3     4     5
Pointer:         arr -> arr+1 -> arr+2 -> arr+3 -> arr+4
```

## Examples

### 1. Basic Array-Pointer Relationship

```c
#include<stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    printf("Array name: %p\n", (void*)arr);
    printf("Address of first element: %p\n", (void*)&arr[0]);
    printf("Are they equal? %s\n", arr == &arr[0] ? "Yes" : "No");
    
    return 0;
}
```

### 2. Accessing Elements Using Pointer Arithmetic

```c
#include<stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Using array notation
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[1] = %d\n", arr[1]);
    
    // Using pointer notation
    printf("*arr = %d\n", *arr);
    printf("*(arr + 1) = %d\n", *(arr + 1));
    
    // Using pointer arithmetic
    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    
    return 0;
}
```

### 3. Pointer Arithmetic with Arrays

```c
#include<stdio.h>

int main() {
    int arr[5] = {100, 200, 300, 400, 500};
    int *ptr = arr;  // ptr points to first element
    
    printf("Using pointer arithmetic:\n");
    for(int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, *(ptr + i));
    }
    
    printf("\nUsing array notation:\n");
    for(int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}
```

## Important Differences

### Array vs Pointer

| Aspect | Array | Pointer |
|--------|-------|---------|
| **Size** | Fixed at declaration | Can be changed |
| **Memory** | Contiguous block | Points to memory location |
| **Assignment** | Cannot be reassigned | Can be reassigned |
| **sizeof** | Returns total size | Returns pointer size |

```c
#include<stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    printf("Sizeof arr: %zu bytes\n", sizeof(arr));
    printf("Sizeof ptr: %zu bytes\n", sizeof(ptr));
    
    // arr = ptr;  // Error: cannot assign to array
    ptr = arr;     // OK: can assign array to pointer
    
    return 0;
}
```

## Common Operations

### 1. Passing Arrays to Functions

```c
#include<stdio.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArrayPointer(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    printArray(arr, 5);
    printArrayPointer(arr, 5);
    
    return 0;
}
```

### 2. Modifying Array Elements

```c
#include<stdio.h>

void modifyArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] *= 2;  // Double each element
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    printf("Before modification:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    modifyArray(arr, 5);
    
    printf("\nAfter modification:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Multi-dimensional Arrays

### 2D Arrays as Pointers

```c
#include<stdio.h>

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // arr[0] points to first row
    printf("First row: ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", arr[0][i]);
    }
    printf("\n");
    
    // Using pointer arithmetic
    printf("First row (pointer): ");
    for(int i = 0; i < 4; i++) {
        printf("%d ", *(arr[0] + i));
    }
    printf("\n");
    
    return 0;
}
```

## Best Practices

1. **Use array notation** for clarity when working with arrays
2. **Use pointer notation** when you need pointer arithmetic
3. **Be careful with bounds** - C doesn't check array bounds
4. **Remember the relationship** `arr[i] == *(arr + i)`
5. **Use sizeof carefully** - it behaves differently for arrays vs pointers

## Common Pitfalls

### 1. Array Decay

```c
#include<stdio.h>

void function(int arr[]) {
    // arr is actually a pointer, not an array
    printf("Sizeof arr in function: %zu\n", sizeof(arr));  // Size of pointer, not array
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Sizeof arr in main: %zu\n", sizeof(arr));  // Size of array
    function(arr);
    return 0;
}
```

### 2. Bounds Checking

```c
#include<stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Dangerous: accessing beyond array bounds
    printf("arr[10] = %d\n", arr[10]);  // Undefined behavior
    
    return 0;
}
``` 