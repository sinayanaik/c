#include <stdio.h>

void printValue(void* ptr, char type) {
    switch (type) {
        case 'i':
            printf("Integer: %d\n", *(int*)ptr);
            break;
        case 'f':
            printf("Float: %f\n", *(float*)ptr);
            break;
        case 'c':
            printf("Char: %c\n", *(char*)ptr);
            break;
        default:
            printf("Unknown type\n");
    }
}

int main() {
    int i = 42;
    float f = 3.14;
    char c = 'A';
    
    printValue(&i, 'i');
    printValue(&f, 'f');
    printValue(&c, 'c');
    
    return 0;
} 