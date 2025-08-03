# Variable Scope and Storage Classes in C

## Overview

Storage classes in C determine three important aspects of variables:

1. **Scope**: Where the value of the variable would be available inside a program
2. **Default Initial Value**: If we do not explicitly initialize that variable
3. **Lifetime**: For how long will that variable exist

## Storage Classes in C

### 1. Automatic Variables (`auto`)

Automatic variables can also be called **local variables** because they are local to a function.

**Characteristics:**
- **Scope**: Local to the function block inside which they are defined
- **Default Initial Value**: Any random value (garbage value)
- **Lifetime**: Till the end of the function/method block where the variable is defined

```c
#include<stdio.h>

void main() {
    int detail;           // Automatic variable
    auto int details;     // Both are same
}
```

### 2. External or Global Variables (`extern`)

**Characteristics:**
- **Scope**: Global - everywhere in the program
- **Default Initial Value**: 0 (zero)
- **Lifetime**: Till the program doesn't finish its execution

**Key Points:**
- These variables are not bound by any function
- They are available everywhere
- Their values can be changed by any function in the program
- The `extern` declaration does not allocate storage for variables

```c
#include<stdio.h>

int number;     // Global variable

void main() {
    number = 10;
    printf("In main: %d\n", number);
    fun1();
    fun2();
}

int fun1() {
    number = 200;
    printf("In fun1: %d\n", number);
}

int fun2() {
    printf("In fun2: %d\n", number);
}
```

### 3. Static Variables (`static`)

**Characteristics:**
- **Scope**: Local to the block in which the variable is defined
- **Default Initial Value**: 0 (Zero)
- **Lifetime**: Till the whole program doesn't finish its execution

**Key Points:**
- A static variable tells the compiler to persist/save the variable until the end of program
- Instead of creating and destroying a variable every time when it comes into and goes out of scope, static variable is initialized only once
- The value persists between function calls

```c
#include<stdio.h>

void function() {
    static int count = 0;  // Static variable
    count++;
    printf("Function called %d times\n", count);
}

void main() {
    function();  // count = 1
    function();  // count = 2
    function();  // count = 3
}
```

### 4. Register Variables (`register`)

**Characteristics:**
- **Scope**: Local to the function in which it is declared
- **Default Initial Value**: Any random value (garbage value)
- **Lifetime**: Till the end of function/method block in which the variable is defined

**Key Points:**
- Register variables inform the compiler to store the variable in CPU register instead of memory
- This can improve performance for frequently accessed variables
- The compiler may ignore the `register` keyword if no registers are available

```c
#include<stdio.h>

void main() {
    register int number;  // Register variable
    number = 10;
    printf("Value: %d\n", number);
}
```

## Summary Table

| Storage Class | Scope | Default Value | Lifetime | Keyword |
|---------------|-------|---------------|----------|---------|
| Automatic | Local to function | Garbage value | Function block | `auto` |
| External | Global | 0 | Program execution | `extern` |
| Static | Local to block | 0 | Program execution | `static` |
| Register | Local to function | Garbage value | Function block | `register` |

## Best Practices

1. **Use `auto`** for local variables (default behavior)
2. **Use `extern`** for global variables that need to be accessed across multiple files
3. **Use `static`** when you need to preserve variable value between function calls
4. **Use `register`** for frequently accessed variables in performance-critical code
5. **Minimize global variables** to avoid naming conflicts and improve code maintainability

## Memory Management Considerations

- **Automatic variables**: Stored on stack, automatically deallocated
- **Static variables**: Stored in data segment, persist throughout program execution
- **Register variables**: Stored in CPU registers for faster access
- **External variables**: Stored in data segment, accessible globally 