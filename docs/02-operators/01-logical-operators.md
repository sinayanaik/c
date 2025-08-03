# Logical Operators in C

## Overview

C language supports **3 logical operators** that are used to combine or modify logical expressions. These operators work with boolean values (true/false) and return boolean results.

## Logical Operators Table

| Operator | Description | Example |
|----------|-------------|---------|
| `&&` | Logical AND | `(a && b)` is false |
| `||` | Logical OR | `(a \|\| b)` is true |
| `!` | Logical NOT | `(!a)` is false |

## Detailed Explanation

### 1. Logical AND (`&&`)

Returns `true` only if **both** operands are `true`.

**Truth Table:**
| A | B | A && B |
|---|---|--------|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

```c
#include<stdio.h>

int main() {
    int a = 5, b = 9;
    
    if (a > 3 && b < 10) {
        printf("Both conditions are true\n");
    }
    
    if (a > 10 && b < 5) {
        printf("This won't execute\n");
    }
    
    return 0;
}
```

### 2. Logical OR (`||`)

Returns `true` if **at least one** operand is `true`.

**Truth Table:**
| A | B | A \|\| B |
|---|---|----------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

```c
#include<stdio.h>

int main() {
    int a = 5, b = 9;
    
    if (a > 10 || b < 10) {
        printf("At least one condition is true\n");
    }
    
    if (a > 3 || b > 15) {
        printf("This will execute\n");
    }
    
    return 0;
}
```

### 3. Logical NOT (`!`)

Returns the **opposite** of the operand's truth value.

**Truth Table:**
| A | !A |
|---|-----|
| 0 | 1 |
| 1 | 0 |

```c
#include<stdio.h>

int main() {
    int a = 5;
    
    if (!(a > 10)) {
        printf("a is NOT greater than 10\n");
    }
    
    if (!a) {
        printf("This won't execute because a is non-zero\n");
    }
    
    return 0;
}
```

## Short-Circuit Evaluation

C uses **short-circuit evaluation** for logical operators:

- **`&&`**: If the first operand is `false`, the second operand is not evaluated
- **`||`**: If the first operand is `true`, the second operand is not evaluated

```c
#include<stdio.h>

int main() {
    int a = 0, b = 5;
    
    // Short-circuit: b++ won't execute because a is 0 (false)
    if (a && b++) {
        printf("This won't execute\n");
    }
    printf("b = %d\n", b);  // b is still 5
    
    // Short-circuit: b++ will execute because a is 1 (true)
    a = 1;
    if (a || b++) {
        printf("This will execute\n");
    }
    printf("b = %d\n", b);  // b is still 5 (short-circuited)
    
    return 0;
}
```

## Complex Logical Expressions

You can combine multiple logical operators to create complex conditions:

```c
#include<stdio.h>

int main() {
    int age = 25;
    int income = 50000;
    int credit_score = 750;
    
    // Complex condition using multiple logical operators
    if ((age >= 18 && age <= 65) && 
        (income >= 30000 || credit_score >= 700)) {
        printf("Eligible for loan\n");
    } else {
        printf("Not eligible for loan\n");
    }
    
    return 0;
}
```

## Operator Precedence

When using multiple operators, remember the precedence:

1. `!` (highest precedence)
2. `&&`
3. `||` (lowest precedence)

```c
#include<stdio.h>

int main() {
    int a = 1, b = 0, c = 1;
    
    // Equivalent to: (a && (!b)) || c
    int result = a && !b || c;
    printf("Result: %d\n", result);
    
    // Use parentheses for clarity
    int result2 = (a && !b) || c;
    printf("Result2: %d\n", result2);
    
    return 0;
}
```

## Common Use Cases

### 1. Range Checking
```c
if (value >= min && value <= max) {
    printf("Value is in range\n");
}
```

### 2. Multiple Conditions
```c
if (age >= 18 && (income >= 50000 || has_co_signer)) {
    printf("Eligible for credit card\n");
}
```

### 3. Input Validation
```c
if (!(input >= 0 && input <= 100)) {
    printf("Invalid input\n");
}
```

## Best Practices

1. **Use parentheses** for complex expressions to avoid confusion
2. **Take advantage of short-circuit evaluation** for efficiency
3. **Keep expressions simple** and readable
4. **Use meaningful variable names** to make logical expressions clear
5. **Test edge cases** to ensure logical expressions work correctly 