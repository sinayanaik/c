# Memory Management - Interview Questions & Answers

## 🎯 Overview
Memory management is crucial in C programming and is frequently tested in interviews. This guide covers stack vs heap, malloc/free, memory leaks, and common pitfalls.

## 📚 Core Concepts

### Stack vs Heap Memory

| Aspect | Stack | Heap |
|--------|-------|------|
| **Allocation** | Automatic | Manual (malloc/free) |
| **Size** | Fixed at compile time | Dynamic at runtime |
| **Speed** | Fast | Slower |
| **Lifetime** | Function scope | Until freed |
| **Fragmentation** | No | Yes |
| **Thread Safety** | Each thread has own stack | Shared |

## 🎯 Interview Questions & Answers

### Q1: What is the difference between stack and heap memory?
**Answer:**
Stack and heap are two different memory allocation methods:

**Stack Memory:**
- Automatically managed by compiler
- LIFO (Last In, First Out) structure
- Variables are automatically deallocated when function returns
- Limited size, fast access
- No fragmentation

**Heap Memory:**
- Manually managed by programmer
- Dynamic allocation with malloc/free
- Must be explicitly freed
- Larger size, slower access
- Can have fragmentation

**Example:**
```c
#include <stdio.h>
#include <stdlib.h>

void stackExample() {
    int x = 10;        // Stack allocation
    int arr[5];        // Stack allocation
    // Automatically freed when function returns
}

void heapExample() {
    int *ptr = (int*)malloc(sizeof(int));  // Heap allocation
    *ptr = 10;
    free(ptr);  // Must manually free
}

int main() {
    stackExample();  // Stack variables automatically freed
    heapExample();   // Heap variables must be manually freed
    return 0;
}
```

### Q2: How does malloc/free work?
**Answer:**
malloc() allocates memory from heap and returns a pointer to the allocated memory. free() deallocates the memory.

**Example:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate single integer
    int *ptr1 = (int*)malloc(sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    *ptr1 = 100;
    
    // Allocate array
    int *ptr2 = (int*)malloc(5 * sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed\n");
        free(ptr1);  // Clean up
        return 1;
    }
    
    // Use memory
    for (int i = 0; i < 5; i++) {
        ptr2[i] = i * 10;
    }
    
    // Free memory
    free(ptr1);
    free(ptr2);
    
    return 0;
}
```

### Q3: What are memory leaks and how to prevent them?
**Answer:**
Memory leaks occur when allocated memory is not freed, causing the program to consume more memory over time.

**Common Causes:**
1. Forgetting to call free()
2. Losing pointer to allocated memory
3. Early return without freeing
4. Exception/error without cleanup

**Example of Memory Leak:**
```c
#include <stdio.h>
#include <stdlib.h>

void memoryLeak() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    // Memory leak: forgot to free(ptr)
}

void anotherLeak() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    ptr = NULL;  // Lost pointer to allocated memory
    // Memory leak: can't free memory anymore
}
```

**Prevention Techniques:**
```c
#include <stdio.h>
#include <stdlib.h>

// Good practice: Always check malloc return
int* safeAllocation() {
    int *ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return ptr;
}

// Good practice: Use cleanup function
void cleanup(int *ptr) {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;  // Prevent dangling pointer
    }
}

int main() {
    int *ptr = safeAllocation();
    if (ptr != NULL) {
        *ptr = 100;
        cleanup(ptr);
    }
    return 0;
}
```

### Q4: What is buffer overflow and how to prevent it?
**Answer:**
Buffer overflow occurs when data is written beyond the allocated memory boundaries.

**Example of Buffer Overflow:**
```c
#include <stdio.h>
#include <string.h>

void bufferOverflow() {
    char buffer[5];
    strcpy(buffer, "This is too long");  // Buffer overflow!
    printf("%s\n", buffer);
}
```

**Prevention Techniques:**
```c
#include <stdio.h>
#include <string.h>

void safeStringCopy() {
    char buffer[5];
    
    // Method 1: Use strncpy with null termination
    strncpy(buffer, "Hello", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    
    // Method 2: Check length before copying
    char *source = "This is too long";
    if (strlen(source) < sizeof(buffer)) {
        strcpy(buffer, source);
    }
    
    // Method 3: Use snprintf
    snprintf(buffer, sizeof(buffer), "%s", "Hello");
}
```

### Q5: What is memory alignment and why is it important?
**Answer:**
Memory alignment refers to placing data at memory addresses that are multiples of the data size. It's important for performance and hardware requirements.

**Example:**
```c
#include <stdio.h>

struct AlignedStruct {
    char a;     // 1 byte
    int b;      // 4 bytes (aligned to 4-byte boundary)
    char c;     // 1 byte
    double d;   // 8 bytes (aligned to 8-byte boundary)
};

struct PackedStruct {
    char a;     // 1 byte
    int b;      // 4 bytes
    char c;     // 1 byte
    double d;   // 8 bytes
} __attribute__((packed));  // No padding

int main() {
    printf("Aligned struct size: %zu\n", sizeof(struct AlignedStruct));
    printf("Packed struct size: %zu\n", sizeof(struct PackedStruct));
    return 0;
}
```

## 🚨 Common Memory Issues

### 1. Double Free
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    free(ptr);
    free(ptr);  // Double free - undefined behavior
    return 0;
}
```

### 2. Use After Free
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 100;
    free(ptr);
    printf("%d\n", *ptr);  // Use after free - undefined behavior
    return 0;
}
```

### 3. Memory Leak in Loops
```c
#include <stdio.h>
#include <stdlib.h>

void memoryLeakInLoop() {
    for (int i = 0; i < 1000; i++) {
        int *ptr = (int*)malloc(sizeof(int));
        *ptr = i;
        // Memory leak: forgot to free(ptr)
    }
}
```

## 🎯 Practice Questions

### Question 1: What will be the output?
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 10;
    free(ptr);
    ptr = NULL;
    
    if (ptr == NULL) {
        printf("Pointer is null\n");
    } else {
        printf("Value: %d\n", *ptr);
    }
    return 0;
}
```

**Answer:** "Pointer is null"

### Question 2: What's wrong with this code?
```c
#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    int *arr = createArray(5);
    // Use array
    return 0;  // Memory leak!
}
```

**Answer:** Memory leak - forgot to free(arr)

### Question 3: What will be the output?
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1 = (int*)malloc(sizeof(int));
    int *ptr2 = ptr1;
    
    *ptr1 = 100;
    free(ptr1);
    
    printf("%d\n", *ptr2);  // What happens?
    return 0;
}
```

**Answer:** Undefined behavior - accessing freed memory

## 🏆 Best Practices

### 1. Always Check malloc Return
```c
int *ptr = (int*)malloc(sizeof(int));
if (ptr == NULL) {
    // Handle allocation failure
    return NULL;
}
```

### 2. Free Memory in Reverse Order
```c
int *ptr1 = malloc(sizeof(int));
int *ptr2 = malloc(sizeof(int));
int *ptr3 = malloc(sizeof(int));

// Free in reverse order
free(ptr3);
free(ptr2);
free(ptr1);
```

### 3. Set Pointers to NULL After Free
```c
free(ptr);
ptr = NULL;  // Prevent dangling pointer
```

### 4. Use sizeof for Portability
```c
int *ptr = malloc(10 * sizeof(int));  // Not malloc(40)
```

### 5. Consider Using Tools
- **Valgrind**: Memory error detection
- **AddressSanitizer**: Advanced memory checking
- **Static analyzers**: cppcheck, splint

## 📚 Additional Resources

- [Dynamic Memory Allocation](./02_dynamic_allocation.md)
- [Memory Leaks Detection](./03_memory_leaks.md)
- [Buffer Overflow Prevention](./04_buffer_overflow.md)
- [Performance Optimization](./../advanced/01_performance.md)

---

**Next: [Dynamic Memory Allocation](./02_dynamic_allocation.md)** 