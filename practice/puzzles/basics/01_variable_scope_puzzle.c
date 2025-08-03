/*
 * Puzzle: Variable Scope and Lifetime
 * 
 * What will be the output of this program?
 * Think about variable scope, lifetime, and initialization.
 */

#include <stdio.h>

int global_var = 10;

void function1() {
    int local_var = 20;
    printf("In function1: local_var = %d\n", local_var);
    printf("In function1: global_var = %d\n", global_var);
}

void function2() {
    int local_var = 30;
    printf("In function2: local_var = %d\n", local_var);
    printf("In function2: global_var = %d\n", global_var);
}

int main() {
    int local_var = 5;
    
    printf("In main: local_var = %d\n", local_var);
    printf("In main: global_var = %d\n", global_var);
    
    function1();
    function2();
    
    printf("Back in main: local_var = %d\n", local_var);
    printf("Back in main: global_var = %d\n", global_var);
    
    return 0;
}

/*
 * Questions:
 * 1. What is the output of this program?
 * 2. Why does each function have its own local_var?
 * 3. How does global_var behave differently from local_var?
 * 4. What happens to local_var when a function returns?
 * 5. Can function1 access the local_var from function2?
 */ 