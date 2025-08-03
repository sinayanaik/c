# Keywords in C Programming

## Overview

Keywords are **reserved words** that have special meaning in the C language. The meaning of C language keywords has already been described in the C compiler. These meanings cannot be changed.

**Key Points:**
- Keywords cannot be used as variable names
- They have predefined meanings in the C compiler
- There are **32 keywords** in the C language
- Keywords must be written in **lower case**

## Complete List of C Keywords

### Data Types
| Keyword | Purpose |
|---------|---------|
| `auto` | Automatic storage class |
| `char` | Character data type |
| `const` | Constant declaration |
| `double` | Double precision floating point |
| `enum` | Enumeration |
| `extern` | External storage class |
| `float` | Single precision floating point |
| `int` | Integer data type |
| `long` | Long integer |
| `register` | Register storage class |
| `short` | Short integer |
| `signed` | Signed data type |
| `sizeof` | Size of data type |
| `static` | Static storage class |
| `struct` | Structure |
| `typedef` | Type definition |
| `union` | Union |
| `unsigned` | Unsigned data type |
| `void` | Void data type |
| `volatile` | Volatile variable |

### Control Flow
| Keyword | Purpose |
|---------|---------|
| `break` | Break from loop or switch |
| `case` | Case in switch statement |
| `continue` | Continue to next iteration |
| `default` | Default case in switch |
| `do` | Do-while loop |
| `else` | Else part of if statement |
| `for` | For loop |
| `goto` | Goto statement |
| `if` | If statement |
| `return` | Return from function |
| `switch` | Switch statement |
| `while` | While loop |

## Rules for Keywords

### 1. Cannot be Used as Variable Names
```c
// Wrong - using keywords as variable names
int int;        // Error
int if;         // Error
int return;     // Error

// Correct - using descriptive names
int integer_value;
int condition;
int return_value;
```

### 2. Must be Written in Lower Case
```c
// Wrong - keywords in upper case
IF (condition) { }
FOR (int i = 0; i < 10; i++) { }

// Correct - keywords in lower case
if (condition) { }
for (int i = 0; i < 10; i++) { }
```

### 3. Specify Type/Kind of Entity
Keywords tell the compiler what type of entity you're declaring:
- `int` - declares an integer variable
- `if` - starts a conditional statement
- `for` - starts a loop
- `return` - returns from a function

## Examples by Category

### Data Type Keywords
```c
int age = 25;                    // Integer
float temperature = 98.6;        // Floating point
char grade = 'A';                // Character
double pi = 3.14159;            // Double precision
const int MAX_SIZE = 100;        // Constant
```

### Control Flow Keywords
```c
if (age >= 18) {
    printf("Adult\n");
} else {
    printf("Minor\n");
}

for (int i = 0; i < 10; i++) {
    printf("%d ", i);
}

while (condition) {
    // Loop body
}

switch (choice) {
    case 1:
        printf("Option 1\n");
        break;
    default:
        printf("Invalid option\n");
}
```

### Storage Class Keywords
```c
auto int local_var;              // Automatic (default)
static int persistent_var;       // Static
extern int global_var;           // External
register int fast_var;           // Register
```

## Common Mistakes

### 1. Using Keywords as Identifiers
```c
// Common mistakes
int class;       // 'class' is not a C keyword, but avoid it
int new;         // 'new' is not a C keyword, but avoid it
int delete;      // 'delete' is not a C keyword, but avoid it
```

### 2. Case Sensitivity
```c
// Wrong
IF (x > 0) { }
FOR (i = 0; i < 10; i++) { }

// Correct
if (x > 0) { }
for (i = 0; i < 10; i++) { }
```

### 3. Misspelling Keywords
```c
// Wrong
whle (condition) { }     // Misspelled 'while'
fro (i = 0; i < 10; i++) { }  // Misspelled 'for'

// Correct
while (condition) { }
for (i = 0; i < 10; i++) { }
```

## Best Practices

### 1. Avoid Reserved Words
Even if a word is not a C keyword, avoid using common programming terms:
```c
// Avoid these as variable names
int class, new, delete, template, typename;
```

### 2. Use Descriptive Names
```c
// Good
int user_age;
int calculate_total();
int is_valid;

// Bad
int a, b, c;
int func();
int flag;
```

### 3. Be Consistent
```c
// Choose one style and stick to it
int user_name;     // snake_case
int userName;      // camelCase
```

## Summary

**Key Points:**
- 32 keywords in C language
- Keywords are reserved and cannot be used as identifiers
- Keywords must be written in lower case
- Keywords specify the type/kind of entity
- Avoid using keywords as variable names
- Be careful with case sensitivity
- Use descriptive names instead of keywords 