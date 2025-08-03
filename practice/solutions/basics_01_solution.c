/*
 * Solution: Variable Scope and Lifetime Puzzle
 * 
 * This program demonstrates the concepts of variable scope and lifetime in C.
 * 
 * Key Concepts:
 * 1. Global variables are accessible throughout the program
 * 2. Local variables are only accessible within their function
 * 3. Each function has its own local variable scope
 * 4. Local variables are destroyed when function returns
 */

#include <stdio.h>

int global_var = 10;  // Global variable - accessible everywhere

void function1() {
    int local_var = 20;  // Local variable - only accessible in function1
    printf("In function1: local_var = %d\n", local_var);
    printf("In function1: global_var = %d\n", global_var);
    // local_var is destroyed when function1 returns
}

void function2() {
    int local_var = 30;  // Different local variable - only accessible in function2
    printf("In function2: local_var = %d\n", local_var);
    printf("In function2: global_var = %d\n", global_var);
    // local_var is destroyed when function2 returns
}

int main() {
    int local_var = 5;  // Local variable - only accessible in main
    
    printf("In main: local_var = %d\n", local_var);
    printf("In main: global_var = %d\n", global_var);
    
    function1();
    function2();
    
    printf("Back in main: local_var = %d\n", local_var);
    printf("Back in main: global_var = %d\n", global_var);
    
    return 0;
}

/*
 * Expected Output:
 * In main: local_var = 5
 * In main: global_var = 10
 * In function1: local_var = 20
 * In function1: global_var = 10
 * In function2: local_var = 30
 * In function2: global_var = 10
 * Back in main: local_var = 5
 * Back in main: global_var = 10
 * 
 * Explanation:
 * 1. Each function has its own local_var with different values
 * 2. global_var is the same everywhere (value: 10)
 * 3. When functions return, their local variables are destroyed
 * 4. main's local_var remains unchanged after function calls
 * 5. Functions cannot access each other's local variables
 * 
 * Key Learning Points:
 * - Scope: Where a variable is accessible
 * - Lifetime: How long a variable exists in memory
 * - Global variables: Scope = entire program, Lifetime = program execution
 * - Local variables: Scope = function block, Lifetime = function execution
 */ 