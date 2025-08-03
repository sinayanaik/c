# Data Types in C Programming

## Overview

Data types specify:
- How we enter data into our programs
- What type of data we enter

A data type determines the type of data a variable will hold. C language has a predefined set of data types to handle various kinds of data that we can use in our programs.

## Classification

C language supports **2 different types** of data types:

### 1. Primary Data Types
These are fundamental data types in C:
- **Integer** (`int`)
- **Floating Point** (`float`) 
- **Character** (`char`)
- **Void** (`void`)

### 2. Derived Data Types
Derived data types are primary data types that are twisted or grouped together:
- **Array**
- **Structure**
- **Union**
- **Pointers**

## 1. Integer Type

Integers are used to store whole numbers.

| Type | Size | Value Range |
|------|------|-------------|
| `int` | 2 or 4 bytes | -32,768 to 32,767 or<br>-2,147,483,648 to 2,147,483,647 |
| `unsigned int` | 2 or 4 bytes | 0 to 65,535 or<br>0 to 4,294,967,295 |
| `short` | 2 bytes | -32,768 to 32,767 |
| `unsigned short` | 2 bytes | 0 to 65,535 |
| `long` | 8 bytes or 4 bytes | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| `unsigned long` | 8 bytes | 0 to 18,446,744,073,709,551,615 |

## 2. Character Type

Character types are used to store character values.

**Characters include:**
- Alphabets (a, b, c, d, e... A, B, C, D...)
- Numbers (1, 2, 3, 4...)
- Special characters (!, @, #, $...)

**Important Rules:**
- Characters must be enclosed within single quotation marks (`''`)
- Examples: `'A'`, `'#'`, `'1'`
- Characters are only allowed to be single digit long
  - ✅ Correct: `'A'`
  - ❌ Incorrect: `'ABC'` (three characters)

| Type | Storage Size | Value Range |
|------|-------------|-------------|
| `char` | 1 byte | -128 to 127 or<br>0 to 255 |
| `unsigned char` | 1 byte | 0 to 255 |
| `signed char` | 1 byte | -128 to 127 |

## 3. Floating Point Type

Floating types are used to store real numbers (both fractional and whole).

| Type | Storage Size | Value Range | Precision |
|------|-------------|-------------|-----------|
| `float` | 4 bytes | 1.2E-38 to 3.4E+38 | 6 decimal places |
| `double` | 8 bytes | 2.3E-308 to 1.7E+308 | 15 decimal places |
| `long double` | 10 bytes | 3.4E-4932 to 1.1E+4932 | 19 decimal places |

> **Note**: 1.2E-38 to 3.4E+38 = 1.2 × 10⁻³⁸ to 3.4 × 10⁺³⁸

## 4. Void Type

Void type means **no value**. This is usually used to specify the type of functions which return nothing.

**Common Uses:**
- Function return type when no value is returned
- Generic pointer type (`void*`)
- Function parameters when no parameters are needed

## Examples

```c
// Integer types
int age = 25;
unsigned int positive_number = 100;
long big_number = 1234567890L;

// Character types
char grade = 'A';
char symbol = '#';

// Floating point types
float price = 19.99f;
double pi = 3.14159265359;
long double precise_value = 3.14159265359L;

// Void type
void function_with_no_return() {
    printf("This function returns nothing\n");
}
```

## Memory Considerations

- Choose appropriate data types to optimize memory usage
- Use `unsigned` types when you know values will always be positive
- Use `long` for large numbers that exceed `int` range
- Use `double` for higher precision calculations

## Type Modifiers

C provides several modifiers to alter the behavior of data types:

- `signed` / `unsigned`: Control sign representation
- `short` / `long`: Control size
- `const`: Make variables read-only
- `volatile`: Indicate variable may change unexpectedly 