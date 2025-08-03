/*
 * Puzzle: Logical Operator Short-Circuiting
 * 
 * What will be the output of this program?
 * Think about short-circuit evaluation of logical operators.
 */

#include <stdio.h>

int function1() {
    printf("function1() called\n");
    return 1;  // Always returns true
}

int function2() {
    printf("function2() called\n");
    return 0;  // Always returns false
}

int function3() {
    printf("function3() called\n");
    return 1;  // Always returns true
}

int main() {
    int result;
    
    printf("=== Puzzle 1: AND operator ===\n");
    result = function1() && function2() && function3();
    printf("Result: %d\n\n", result);
    
    printf("=== Puzzle 2: OR operator ===\n");
    result = function2() || function1() || function3();
    printf("Result: %d\n\n", result);
    
    printf("=== Puzzle 3: Mixed operators ===\n");
    result = function1() && function2() || function3();
    printf("Result: %d\n\n", result);
    
    printf("=== Puzzle 4: Complex expression ===\n");
    result = (function2() && function1()) || (function1() && function3());
    printf("Result: %d\n\n", result);
    
    printf("=== Puzzle 5: Assignment with short-circuit ===\n");
    int a = 5, b = 0;
    int c = (a != 0) && (b = 10);  // b will be assigned only if a != 0
    printf("a = %d, b = %d, c = %d\n\n", a, b, c);
    
    printf("=== Puzzle 6: Division by zero prevention ===\n");
    int divisor = 0;
    int dividend = 10;
    
    if (divisor != 0 && dividend / divisor > 5) {
        printf("Division result is greater than 5\n");
    } else {
        printf("Division not performed or result <= 5\n");
    }
    
    return 0;
}

/*
 * Questions:
 * 1. Which functions are called in each puzzle?
 * 2. Why are some functions not called?
 * 3. What is the difference between && and || short-circuiting?
 * 4. How does short-circuiting help prevent errors?
 * 5. What is the precedence between && and ||?
 * 
 * Key Concepts:
 * - && (AND): Stops evaluating if any operand is false
 * - || (OR): Stops evaluating if any operand is true
 * - Short-circuiting can prevent errors and improve performance
 * - The order of evaluation matters for side effects
 */ 