/*
 * Exercise: Array Operations
 * 
 * Write a program that performs various operations on an array:
 * 1. Find the maximum element
 * 2. Find the minimum element
 * 3. Calculate the sum of all elements
 * 4. Calculate the average of all elements
 * 5. Count the number of even and odd elements
 * 6. Reverse the array
 * 
 * Requirements:
 * - Create an array of integers (you can initialize it or take input)
 * - Implement separate functions for each operation
 * - Display the results clearly
 * - Handle edge cases (empty array, single element)
 * 
 * Example Output:
 * Array: [5, 2, 8, 1, 9, 3, 7, 4, 6]
 * Maximum: 9
 * Minimum: 1
 * Sum: 45
 * Average: 5.00
 * Even elements: 4
 * Odd elements: 5
 * Reversed array: [6, 4, 7, 3, 9, 1, 8, 2, 5]
 */

#include <stdio.h>

// Function prototypes
int findMax(int arr[], int size);
int findMin(int arr[], int size);
int calculateSum(int arr[], int size);
float calculateAverage(int arr[], int size);
void countEvenOdd(int arr[], int size, int *even, int *odd);
void reverseArray(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    // TODO: Implement your solution here
    
    return 0;
}

// TODO: Implement all the functions above

/*
 * Hints:
 * 1. Use loops to iterate through the array
 * 2. Initialize variables properly before using them
 * 3. For average calculation, use float or double
 * 4. For reversing, you can use a temporary variable
 * 5. Consider using const for array parameters that shouldn't be modified
 * 
 * Extension Challenges:
 * 1. Add sorting functionality (bubble sort, selection sort)
 * 2. Implement binary search on sorted array
 * 3. Add functionality to find duplicate elements
 * 4. Implement array rotation (left/right)
 * 5. Add support for dynamic array size (user input)
 */ 