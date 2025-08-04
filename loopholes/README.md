# C Programming Loopholes & Clever Tricks

This folder contains clever C programming examples that demonstrate unexpected behavior, smart implementations, and cool features of the C language.

## Examples Overview

### 1. Pointer Swap Trick (`01_pointer_swap_trick.c`)
**Demonstrates:** The difference between pass-by-value and pass-by-reference

**Key Insight:** The `swap_incorrect` function doesn't work because it only swaps local copies of the parameters.

**Output:**
```
Before any swap: x=5, y=10
Inside swap_incorrect: a=5, b=10
After swap_incorrect: a=10, b=5
After swap_incorrect: x=5, y=10  ← Values unchanged!
Inside swap_correct: *a=5, *b=10
After swap_correct: *a=10, *b=5
After swap_correct: x=10, y=5    ← Values actually swapped!
```

### 2. Array Decay Trick (`02_array_decay_trick.c`)
**Demonstrates:** How arrays decay to pointers and pointer arithmetic

**Key Insights:**
- `arr == &arr[0]` is always true
- `arr[i]` is equivalent to `*(arr + i)` and even `i[arr]`
- `sizeof(arr)` vs `sizeof(ptr)` behavior

**Output:**
```
arr: 0x7fff2f004720
&arr[0]: 0x7fff2f004720
arr == &arr[0]: TRUE
Using arr[i]: 1 2 3 4 5 
Using *(arr + i): 1 2 3 4 5 
Using i[arr]: 1 2 3 4 5        ← Same result!
sizeof(arr): 20 bytes
sizeof(ptr): 8 bytes            ← Only pointer size!
```

### 3. Bitwise Tricks (`03_bitwise_tricks.c`)
**Demonstrates:** Clever bit manipulation techniques

**Key Tricks:**
- Power of 2 check: `n > 0 && (n & (n - 1)) == 0`
- Brian Kernighan's algorithm for counting set bits
- XOR swap without temp variable
- Even/odd check using `!(n & 1)`
- Absolute value without branching
- Min/max without conditional statements

**Output:**
```
1 is power of 2: YES
2 is power of 2: YES
4 is power of 2: YES
...
Set bits in 7: 3
...
1 is odd
2 is even
...
abs(-5) = 5
...
min(5, 10) = 5
max(5, 10) = 10
```

### 4. Scope Tricks (`04_scope_tricks.c`)
**Demonstrates:** Variable scope and unexpected behavior

**Key Insights:**
- Global vs local variable shadowing
- Static variables retain values between function calls
- Block scope behavior
- Uninitialized variables have undefined behavior

**Output:**
```
In main: global_var = 100
Inside function: local_var = 50, global_var = 100
After shadowing: local_var = 50, global_var = 200  ← Local shadows global!
Back in main: global_var = 100                     ← Global unchanged
Function called 1 times
Function called 2 times
Function called 3 times                            ← Static retains value
Uninitialized x = 29304 (undefined behavior!)      ← Random value!
Uninitialized static y = 0 (always 0)             ← Always initialized
```

### 5. Operator Precedence Tricks (`05_operator_precedence_tricks.c`)
**Demonstrates:** Operator precedence and type conversion surprises

**Key Insights:**
- Arithmetic operators have higher precedence than bitwise
- Assignment is right-associative
- Short-circuit evaluation behavior
- Integer division vs floating-point division
- Pointer arithmetic with different types

**Output:**
```
a + b * c = 155 (not 225)                        ← Multiplication first
a & b + c = 1 (not 15)                           ← Addition before AND
x = y = 5: x=5, y=5, result=5                    ← Right-associative
5 / 2 = 2.000000 (integer division!)             ← Integer division!
(float)5 / 2 = 2.500000                          ← Float division
max_int + 1 = -2147483648 (overflow!)            ← Integer overflow
0[ptr] = 1 (same as ptr[0]!)                     ← Array indexing trick
```

### 6. Macro Tricks (`06_macro_tricks.c`)
**Demonstrates:** Macro expansion issues and clever macro techniques

**Key Insights:**
- Macros are text substitution, not function calls
- Side effects in macro arguments are evaluated multiple times
- Stringification and token concatenation
- Variadic macros
- Type checking with macros

**Output:**
```
SQUARE(y + 1) = 5 (wrong!)                       ← Expands to y + 1 * y + 1
SQUARE_SAFE(y + 1) = 9 (correct)                 ← Properly parenthesized
MAX(++counter, 5) = 5, counter = 1               ← Side effect evaluated twice
STRINGIFY(Hello) = Hello                          ← Stringification
CONCAT(var, 12) = 42                             ← Token concatenation
```

## Common Themes

### Unexpected Behavior
1. **Pass-by-value vs Pass-by-reference:** Functions can't modify original variables without pointers
2. **Array decay:** Arrays automatically become pointers when passed to functions
3. **Operator precedence:** Can lead to completely different results than expected
4. **Type conversion:** Integer division, overflow, and implicit conversions
5. **Scope issues:** Variable shadowing and uninitialized variables

### Smart Implementations
1. **Bitwise tricks:** Power of 2 check, XOR swap, set bit counting
2. **Pointer arithmetic:** Array indexing with `i[arr]`, pointer arithmetic
3. **Macro techniques:** Stringification, token concatenation, variadic macros
4. **Branchless code:** Min/max, absolute value without conditionals
5. **Short-circuit evaluation:** Using logical operators for conditional execution

### Cool Features
1. **Array-pointer duality:** `arr[i]` equals `*(arr + i)` equals `i[arr]`
2. **Macro text substitution:** Powerful but dangerous
3. **Bit manipulation:** Efficient algorithms using bitwise operations
4. **Static variables:** Retain values between function calls
5. **Pointer arithmetic:** Different behavior with different types

## Compilation and Running

To compile and run all examples:
```bash
gcc -o example.out example.c
./example.out
```

## Learning Value

These examples teach:
- **Why** certain behaviors occur (understanding the language)
- **How** to avoid common pitfalls
- **When** to use clever techniques vs readable code
- **What** to expect from different language features

Remember: While these tricks are clever, readability and maintainability should often take precedence in production code! 