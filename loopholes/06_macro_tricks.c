#include <stdio.h>

// TRICK: Macros vs Functions - unexpected behavior
#define SQUARE(x) (x * x)
#define SQUARE_SAFE(x) ((x) * (x))

int square_function(int x) {
    return x * x;
}

// TRICK: Macro with side effects
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// TRICK: Stringification macro
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

// TRICK: Token concatenation
#define CONCAT(a, b) a##b

// TRICK: Conditional compilation
#define DEBUG 1
#define LOG(msg) do { if (DEBUG) printf("DEBUG: %s\n", msg); } while(0)

// TRICK: Multi-line macro using do-while(0)
#define SWAP(a, b) do { \
    typeof(a) temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)

void macro_tricks() {
    printf("=== Macro vs Function ===\n");
    
    int x = 5;
    printf("SQUARE(5) = %d\n", SQUARE(x));
    printf("square_function(5) = %d\n", square_function(x));
    
    // TRICK: Macro expansion with side effects
    int a = 2, b = 3;
    printf("MAX(a++, b++) = %d\n", MAX(a++, b++));
    printf("After macro: a = %d, b = %d\n", a, b);
    
    // TRICK: Stringification
    printf("STRINGIFY(Hello) = %s\n", STRINGIFY(Hello));
    printf("TOSTRING(__LINE__) = %s\n", TOSTRING(__LINE__));
    
    // TRICK: Token concatenation
    int var12 = 42;
    printf("CONCAT(var, 12) = %d\n", CONCAT(var, 12));
    
    // TRICK: Conditional logging
    LOG("This is a debug message");
    
    printf("\n=== Macro Expansion Issues ===\n");
    
    // TRICK: Unsafe macro expansion
    int y = 2;
    printf("SQUARE(y + 1) = %d (wrong!)\n", SQUARE(y + 1));
    printf("SQUARE_SAFE(y + 1) = %d (correct)\n", SQUARE_SAFE(y + 1));
    
    // TRICK: Multiple evaluation
    int counter = 0;
    int result = MAX(++counter, 5);
    printf("MAX(++counter, 5) = %d, counter = %d\n", result, counter);
}

// TRICK: Variadic macros
#define PRINT_ARGS(...) printf(__VA_ARGS__)

// TRICK: Macro to get array size
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// TRICK: Macro for debugging
#define DEBUG_PRINT(fmt, ...) \
    printf("[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)

void advanced_macro_tricks() {
    printf("\n=== Advanced Macro Tricks ===\n");
    
    // TRICK: Variadic macro
    PRINT_ARGS("Multiple arguments: %d, %s, %f\n", 42, "hello", 3.14);
    
    // TRICK: Array size macro
    int arr[] = {1, 2, 3, 4, 5};
    printf("Array size: %zu\n", ARRAY_SIZE(arr));
    
    // TRICK: Debug macro
    DEBUG_PRINT("Debug message with value: %d", 100);
    
    // TRICK: Macro for type checking (compile-time)
    #define CHECK_TYPE(var, type) \
        (void)(&(var) == (type *)0)
    
    int int_var = 10;
    CHECK_TYPE(int_var, int);  // Compiles fine
    // CHECK_TYPE(int_var, char);  // Would cause compilation error
}

int main() {
    macro_tricks();
    advanced_macro_tricks();
    
    return 0;
} 