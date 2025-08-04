#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    printf("Array name as pointer:\n");
    printf("arr = %p\n", (void*)arr);
    printf("&arr[0] = %p\n", (void*)&arr[0]);
    printf("arr == &arr[0]: %s\n\n", arr == &arr[0] ? "True" : "False");
    
    printf("Accessing elements:\n");
    printf("arr[2] = %d\n", arr[2]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("*(&arr[0] + 2) = %d\n", *(arr + 2));
    
    return 0;
} 