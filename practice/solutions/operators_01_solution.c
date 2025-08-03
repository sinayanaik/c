/*
 * Solution: Logical Operator Short-Circuiting Puzzle
 * 
 * This program demonstrates short-circuit evaluation of logical operators.
 * 
 * Key Concepts:
 * 1. && (AND): Stops evaluating if any operand is false
 * 2. || (OR): Stops evaluating if any operand is true
 * 3. Short-circuiting can prevent errors and improve performance
 * 4. The order of evaluation matters for side effects
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
    // function1() returns true, so function2() is called
    // function2() returns false, so function3() is NOT called
    result = function1() && function2() && function3();
    printf("Result: %d\n\n", result);
    
    printf("=== Puzzle 2: OR operator ===\n");
    // function2() returns false, so function1() is called
    // function1() returns true, so function3() is NOT called
    result = function2() || function1() || function3();
    printf("Result: %d\n\n", result);
    
    printf("=== Puzzle 3: Mixed operators ===\n");
    // Due to operator precedence: && has higher precedence than ||
    // So this is evaluated as: (function1() && function2()) || function3()
    // function1() && function2() = false, so function3() is called
    result = function1() && function2() || function3();
    printf("Result: %d\n\n", result);
    
    printf("=== Puzzle 4: Complex expression ===\n");
    // (function2() && function1()) || (function1() && function3())
    // First part: function2() returns false, so function1() is NOT called
    // Second part: function1() returns true, so function3() is called
    result = (function2() && function1()) || (function1() && function3());
    printf("Result: %d\n\n", result);
    
    printf("=== Puzzle 5: Assignment with short-circuit ===\n");
    int a = 5, b = 0;
    // a != 0 is true, so b = 10 is executed
    int c = (a != 0) && (b = 10);
    printf("a = %d, b = %d, c = %d\n\n", a, b, c);
    
    printf("=== Puzzle 6: Division by zero prevention ===\n");
    int divisor = 0;
    int dividend = 10;
    
    // divisor != 0 is false, so dividend / divisor is NOT evaluated
    // This prevents division by zero error
    if (divisor != 0 && dividend / divisor > 5) {
        printf("Division result is greater than 5\n");
    } else {
        printf("Division not performed or result <= 5\n");
    }
    
    return 0;
}

/*
 * Expected Output:
 * === Puzzle 1: AND operator ===
 * function1() called
 * function2() called
 * Result: 0
 * 
 * === Puzzle 2: OR operator ===
 * function2() called
 * function1() called
 * Result: 1
 * 
 * === Puzzle 3: Mixed operators ===
 * function1() called
 * function2() called
 * function3() called
 * Result: 1
 * 
 * === Puzzle 4: Complex expression ===
 * function2() called
 * function1() called
 * function3() called
 * Result: 1
 * 
 * === Puzzle 5: Assignment with short-circuit ===
 * a = 5, b = 10, c = 1
 * 
 * === Puzzle 6: Division by zero prevention ===
 * Division not performed or result <= 5
 * 
 * Explanation:
 * 1. AND (&&): Stops at first false operand
 * 2. OR (||): Stops at first true operand
 * 3. Short-circuiting prevents unnecessary evaluations
 * 4. Short-circuiting can prevent errors (like division by zero)
 * 5. Operator precedence affects evaluation order
 * 
 * Key Learning Points:
 * - Short-circuiting improves performance
 * - Short-circuiting prevents errors
 * - Order of evaluation matters for side effects
 * - Understanding precedence is crucial
 */ 