# Pointer Basics - Interview Questions & Answers

## 🎯 Overview
Pointers are the most important concept in C programming and are heavily tested in interviews. This guide covers fundamental pointer concepts with real interview questions and practical examples.

## 📚 Core Concepts

### What is a Pointer?
A pointer is a variable that stores the memory address of another variable.

```c
int x = 10;        // Variable
int *ptr = &x;     // Pointer to x
```

### Basic Pointer Operations
```c
int x = 10;
int *ptr = &x;

printf("Value of x: %d\n", x);           // 10
printf("Address of x: %p\n", (void*)&x); // Memory address
printf("Value of ptr: %p\n", (void*)ptr); // Same address
printf("Value pointed by ptr: %d\n", *ptr); // 10
```

## 🎯 Interview Questions & Answers

### Q1: What is a pointer and why do we use it?
**Answer:**
A pointer is a variable that stores the memory address of another variable. We use pointers for:

1. **Dynamic Memory Allocation** - Allocate memory at runtime
2. **Pass by Reference** - Modify original variables in functions
3. **Array Manipulation** - Efficient array operations
4. **Data Structures** - Linked lists, trees, graphs
5. **System Programming** - Direct memory access

**Example:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dynamic memory allocation
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 100;
    printf("Value: %d\n", *ptr);
    free(ptr);
    return 0;
}
```

### Q2: What is the difference between array and pointer?
**Answer:**

| Aspect | Array | Pointer |
|--------|-------|---------|
| **Declaration** | `int arr[5];` | `int *ptr;` |
| **Size** | Fixed at declaration | Can be changed |
| **Assignment** | Cannot be reassigned | Can be reassigned |
| **sizeof** | Returns total size | Returns pointer size |
| **Memory** | Contiguous block | Points to memory location |

**Example:**
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    printf("sizeof(arr): %zu\n", sizeof(arr));  // 20 bytes
    printf("sizeof(ptr): %zu\n", sizeof(ptr));  // 8 bytes (on 64-bit)
    
    // arr = ptr;  // Error: cannot assign to array
    ptr = arr;     // OK: can assign array to pointer
    
    return 0;
}
```

### Q3: What is void pointer and when do we use it?
**Answer:**
A void pointer is a pointer that can point to any data type. It's used when you need a generic pointer.

**Example:**
```c
#include <stdio.h>
#include <stdlib.h>

void printValue(void *ptr, char type) {
    switch(type) {
        case 'i':
            printf("Integer: %d\n", *(int*)ptr);
            break;
        case 'f':
            printf("Float: %f\n", *(float*)ptr);
            break;
        case 'c':
            printf("Char: %c\n", *(char*)ptr);
            break;
    }
}

int main() {
    int i = 10;
    float f = 3.14;
    char c = 'A';
    
    printValue(&i, 'i');
    printValue(&f, 'f');
    printValue(&c, 'c');
    
    return 0;
}
```

### Q4: What is a null pointer and how to check it?
**Answer:**
A null pointer is a pointer that doesn't point to any valid memory location. It's used to indicate "no value" or "error condition".

**Example:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;  // Null pointer
    
    // Check for null pointer
    if (ptr == NULL) {
        printf("Pointer is null\n");
    }
    
    // Safe way to use pointer
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
    } else {
        printf("Pointer is null, cannot dereference\n");
    }
    
    return 0;
}
```

### Q5: What is pointer arithmetic?
**Answer:**
Pointer arithmetic allows you to perform arithmetic operations on pointers. The arithmetic is based on the size of the data type.

**Example:**
```c
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    
    printf("ptr[0] = %d\n", ptr[0]);     // 10
    printf("*(ptr + 1) = %d\n", *(ptr + 1)); // 20
    printf("ptr[2] = %d\n", ptr[2]);     // 30
    
    // Pointer arithmetic
    ptr++;  // Move to next element
    printf("After ptr++: %d\n", *ptr);    // 20
    
    ptr += 2;  // Move 2 elements forward
    printf("After ptr += 2: %d\n", *ptr); // 40
    
    return 0;
}
```

## 🚨 Common Pitfalls

### 1. Dangling Pointers
```c
#include <stdio.h>
#include <stdlib.h>

int* createValue() {
    int x = 10;
    return &x;  // DANGEROUS: x goes out of scope
}

int main() {
    int *ptr = createValue();  // ptr now points to invalid memory
    printf("%d\n", *ptr);      // Undefined behavior
    return 0;
}
```

**Solution:**
```c
#include <stdio.h>
#include <stdlib.h>

int* createValue() {
    int *x = (int*)malloc(sizeof(int));
    *x = 10;
    return x;  // Safe: memory allocated on heap
}

int main() {
    int *ptr = createValue();
    printf("%d\n", *ptr);
    free(ptr);  // Don't forget to free
    return 0;
}
```

### 2. Uninitialized Pointers
```c
#include <stdio.h>

int main() {
    int *ptr;  // Uninitialized pointer
    printf("%d\n", *ptr);  // Undefined behavior
    return 0;
}
```

**Solution:**
```c
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Initialize to NULL
    if (ptr != NULL) {
        printf("%d\n", *ptr);
    }
    return 0;
}
```

## 🎯 Practice Questions

### Question 1: What will be the output?
```c
#include <stdio.h>

int main() {
    int x = 5;
    int *ptr = &x;
    int **pptr = &ptr;
    
    printf("x = %d\n", x);
    printf("*ptr = %d\n", *ptr);
    printf("**pptr = %d\n", **pptr);
    
    return 0;
}
```

**Answer:** All will print 5

### Question 2: What will be the output?
```c
#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};
    int *ptr = arr;
    
    printf("%d\n", *ptr++);
    printf("%d\n", *ptr);
    printf("%d\n", (*ptr)++);
    printf("%d\n", *ptr);
    
    return 0;
}
```

**Answer:** 1, 2, 2, 3

### Question 3: What will be the output?
```c
#include <stdio.h>

void modify(int *ptr) {
    *ptr = 100;
}

int main() {
    int x = 10;
    printf("Before: %d\n", x);
    modify(&x);
    printf("After: %d\n", x);
    return 0;
}
```

**Answer:** Before: 10, After: 100

## 🏆 Key Takeaways

1. **Pointers store memory addresses**
2. **Use NULL for uninitialized pointers**
3. **Check for NULL before dereferencing**
4. **Be careful with pointer arithmetic**
5. **Avoid dangling pointers**
6. **Free allocated memory**
7. **Understand array-pointer relationship**

## 📚 Additional Resources

- [Pointer Arithmetic](./02_pointer_arithmetic.md)
- [Function Pointers](./03_function_pointers.md)
- [Double Pointers](./04_double_pointers.md)
- [Memory Management](./../memory/01_memory_basics.md)

---

**Next: [Pointer Arithmetic](./02_pointer_arithmetic.md)** 