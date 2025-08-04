#include <stdio.h>

// TRICK: Array decay to pointer demonstration
void array_decay_trick() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    printf("arr: %p\n", (void*)arr);
    printf("&arr[0]: %p\n", (void*)&arr[0]);
    printf("arr == &arr[0]: %s\n", arr == &arr[0] ? "TRUE" : "FALSE");
    
    // Clever: Using pointer arithmetic to access array
    printf("Using arr[i]: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Using *(arr + i): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    
    // TRICK: Array indexing is just pointer arithmetic!
    printf("Using i[arr]: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i[arr]);  // This works! arr[i] == i[arr]
    }
    printf("\n");
}

// TRICK: sizeof behavior with arrays vs pointers
void sizeof_trick() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    printf("sizeof(arr): %zu bytes\n", sizeof(arr));
    printf("sizeof(ptr): %zu bytes\n", sizeof(ptr));
    printf("sizeof(*ptr): %zu bytes\n", sizeof(*ptr));
    
    // TRICK: Calculate array size using sizeof
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array size: %d\n", size);
}

int main() {
    printf("=== Array Decay Trick ===\n");
    array_decay_trick();
    
    printf("\n=== Sizeof Trick ===\n");
    sizeof_trick();
    
    return 0;
} 