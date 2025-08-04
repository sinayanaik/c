#include <stdio.h>

int main() {
    int x = 10;
    float y = 3.14;
    char ch = 'A';
    
    printf("Address of x: %p\n", (void*)&x);
    printf("Address of y: %p\n", (void*)&y);
    printf("Address of ch: %p\n", (void*)&ch);
    
    // Store addresses in pointers
    int* ptr_x = &x;
    float* ptr_y = &y;
    char* ptr_ch = &ch;
    
    printf("ptr_x = %p\n", (void*)ptr_x);
    printf("ptr_y = %p\n", (void*)ptr_y);
    printf("ptr_ch = %p\n", (void*)ptr_ch);
    
    return 0;
} 