# Identifiers in C Programming

## Overview

Informally, we can say **Identifiers = variables**, but this is not entirely accurate. In C language, identifiers are the names given to:

- **Variables**
- **Constants**
- **Functions**
- **User-defined data types**

## Definition

An identifier is a sequence of characters used to identify various program elements such as variables, functions, arrays, etc.

## Rules for Identifiers

### 1. Character Set
An identifier can only have:
- **Alphanumeric characters** (a-z, A-Z, 0-9)
- **Underscore** (_)

### 2. First Character
The first character of an identifier can only contain:
- **Alphabet** (a-z, A-Z)
- **Underscore** (_)

**Cannot start with:**
- Numbers (0-9)
- Special characters (except underscore)

### 3. Case Sensitivity
Identifiers are **case sensitive** in C. For example:
- `var` and `Var` are two different identifiers
- `age` and `Age` are different identifiers

### 4. Keywords Restriction
**Keywords are not allowed** to be used as identifiers.

### 5. Special Characters
No special characters are permitted in identifiers, except underscore (_).

**Not allowed:**
- Semicolon (;)
- Period (.)
- Whitespaces
- Slash (/)
- Comma (,)
- Any other special characters

## Examples

### ✅ Valid Identifiers

```c
int age;           // Simple variable name
int _count;        // Starts with underscore
int user_name;     // Contains underscore
int MAX_SIZE;      // All caps (convention for constants)
int firstName;     // Camel case
int total_count;   // Snake case
```

### ❌ Invalid Identifiers

```c
int 2age;          // Starts with number
int user-name;     // Contains hyphen
int user name;     // Contains space
int if;            // Keyword
int @symbol;       // Special character
int user.name;     // Contains period
```

## Naming Conventions

### 1. Variables and Functions
```c
int userAge;           // camelCase
int calculate_total();  // snake_case
int MAX_CONSTANT;      // UPPER_CASE for constants
```

### 2. Functions
```c
void getUserData();     // camelCase
void calculate_average(); // snake_case
```

### 3. Constants
```c
#define MAX_SIZE 100
#define PI 3.14159
const int BUFFER_SIZE = 1024;
```

## Best Practices

### 1. Descriptive Names
```c
// Good
int student_count;
int calculate_average_score();

// Bad
int sc;
int calc();
```

### 2. Consistent Style
```c
// Choose one style and stick to it
int user_name;     // snake_case
int userAge;       // camelCase
```

### 3. Meaningful Names
```c
// Good
int temperature;
int max_attempts;
void validate_input();

// Bad
int temp;
int ma;
void vi();
```

## Common Patterns

### 1. Boolean Variables
```c
int is_valid;
int has_permission;
int can_edit;
```

### 2. Counter Variables
```c
int i, j, k;        // Simple counters
int count;
int index;
```

### 3. Pointer Variables
```c
int *ptr;
int *data_ptr;
char *string_ptr;
```

## Scope and Visibility

Identifiers have different scopes depending on where they are declared:

```c
#include<stdio.h>

int global_var;     // Global identifier

void function() {
    int local_var;  // Local identifier
    // global_var is accessible here
}

int main() {
    int main_var;   // Local to main
    // global_var is accessible here
    // local_var is NOT accessible here
    return 0;
}
```

## Length Limitations

- **ANSI C**: At least 31 characters for external identifiers
- **Internal identifiers**: At least 63 characters
- **Modern compilers**: Usually support much longer names

## Common Mistakes to Avoid

### 1. Using Keywords
```c
// Wrong
int int;
int if;
int return;

// Correct
int integer_value;
int condition;
int return_value;
```

### 2. Starting with Numbers
```c
// Wrong
int 1st_value;
int 2nd_attempt;

// Correct
int first_value;
int second_attempt;
```

### 3. Using Special Characters
```c
// Wrong
int user-name;
int file@name;
int data#value;

// Correct
int user_name;
int file_name;
int data_value;
```

## Summary

**Important Note**: An identifier can be a variable, but not all identifiers are variables. Identifiers can represent various program elements including variables, functions, constants, and user-defined types.

**Key Points:**
- Use only alphanumeric characters and underscore
- Start with letter or underscore
- Be case sensitive
- Avoid keywords
- Use descriptive names
- Follow consistent naming conventions 