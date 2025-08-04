#include <stdio.h>

// Global variable - accessible everywhere
int global_var = 100;

// TRICK: Function that demonstrates scope issues
void scope_trick() {
    int local_var = 50;
    printf("Inside function: local_var = %d, global_var = %d\n", local_var, global_var);
    
    // TRICK: Shadowing - local variable hides global
    int global_var = 200;  // This shadows the global variable!
    printf("After shadowing: local_var = %d, global_var = %d\n", local_var, global_var);
    
    // TRICK: Access global variable using :: (not available in C, but concept)
    // In C, we can't access the global directly when shadowed
    printf("Cannot access original global_var when shadowed!\n");
}

// TRICK: Static variable retains value between calls
void static_trick() {
    static int count = 0;
    count++;
    printf("Function called %d times\n", count);
}

// TRICK: Variable scope in blocks
void block_scope_trick() {
    int x = 10;
    printf("Before block: x = %d\n", x);
    
    {
        int x = 20;  // New x in this block
        printf("Inside block: x = %d\n", x);
    }
    
    printf("After block: x = %d\n", x);  // Original x is back
}

// TRICK: Unexpected behavior with uninitialized variables
void uninitialized_trick() {
    int x;
    printf("Uninitialized x = %d (undefined behavior!)\n", x);
    
    // TRICK: Static variables are automatically initialized to 0
    static int y;
    printf("Uninitialized static y = %d (always 0)\n", y);
}

int main() {
    printf("=== Global vs Local Scope ===\n");
    printf("In main: global_var = %d\n", global_var);
    scope_trick();
    printf("Back in main: global_var = %d\n", global_var);
    
    printf("\n=== Static Variable Trick ===\n");
    for (int i = 0; i < 3; i++) {
        static_trick();
    }
    
    printf("\n=== Block Scope Trick ===\n");
    block_scope_trick();
    
    printf("\n=== Uninitialized Variable Trick ===\n");
    uninitialized_trick();
    
    return 0;
} 