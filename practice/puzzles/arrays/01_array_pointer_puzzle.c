/*
 * Puzzle: Array-Pointer Relationships
 * 
 * What will be the output of this program?
 * Think about array-pointer relationships and memory layout.
 */

#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    
    printf("=== Puzzle 1: Array name as pointer ===\n");
    printf("arr = %p\n", (void*)arr);
    printf("&arr[0] = %p\n", (void*)&arr[0]);
    printf("arr == &arr[0]: %s\n\n", arr == &arr[0] ? "True" : "False");
    
    printf("=== Puzzle 2: Pointer arithmetic ===\n");
    printf("*ptr = %d\n", *ptr);
    printf("*(ptr + 1) = %d\n", *(ptr + 1));
    printf("ptr[1] = %d\n", ptr[1]);
    printf("*(arr + 2) = %d\n", *(arr + 2));
    printf("arr[2] = %d\n\n", arr[2]);
    
    printf("=== Puzzle 3: Array indexing vs pointer arithmetic ===\n");
    printf("arr[3] = %d\n", arr[3]);
    printf("*(arr + 3) = %d\n", *(arr + 3));
    printf("*(ptr + 3) = %d\n", *(ptr + 3));
    printf("ptr[3] = %d\n\n", ptr[3]);
    
    printf("=== Puzzle 4: Pointer increment ===\n");
    ptr++;
    printf("After ptr++: *ptr = %d\n", *ptr);
    printf("ptr[0] = %d\n", ptr[0]);
    printf("ptr[-1] = %d\n\n", ptr[-1]);
    
    printf("=== Puzzle 5: Array bounds ===\n");
    printf("arr[4] = %d\n", arr[4]);
    printf("arr[5] = %d (undefined behavior)\n", arr[5]);
    printf("*(arr + 5) = %d (undefined behavior)\n\n", *(arr + 5));
    
    printf("=== Puzzle 6: sizeof differences ===\n");
    printf("sizeof(arr) = %zu\n", sizeof(arr));
    printf("sizeof(ptr) = %zu\n", sizeof(ptr));
    printf("sizeof(arr[0]) = %zu\n\n", sizeof(arr[0]));
    
    printf("=== Puzzle 7: Multi-dimensional array ===\n");
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *matrix_ptr = (int*)matrix;
    
    printf("matrix[0][1] = %d\n", matrix[0][1]);
    printf("*(matrix_ptr + 1) = %d\n", *(matrix_ptr + 1));
    printf("matrix_ptr[4] = %d\n\n", matrix_ptr[4]);
    
    printf("=== Puzzle 8: String arrays ===\n");
    char str[] = "Hello";
    char *str_ptr = str;
    
    printf("str = %s\n", str);
    printf("str_ptr = %s\n", str_ptr);
    printf("str[2] = %c\n", str[2]);
    printf("*(str_ptr + 2) = %c\n", *(str_ptr + 2));
    
    return 0;
}

/*
 * Questions:
 * 1. Why are arr and &arr[0] equal?
 * 2. What is the difference between arr[i] and *(arr + i)?
 * 3. Why does sizeof(arr) give different results than sizeof(ptr)?
 * 4. What happens when you access arr[5] or arr[-1]?
 * 5. How does pointer arithmetic work with different data types?
 * 6. What is the relationship between arrays and pointers in C?
 * 
 * Key Concepts:
 * - Array name decays to pointer to first element
 * - arr[i] is equivalent to *(arr + i)
 * - Pointer arithmetic is based on data type size
 * - sizeof behaves differently for arrays vs pointers
 * - Array bounds checking is not automatic in C
 */ 