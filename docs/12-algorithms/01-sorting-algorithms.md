# Sorting Algorithms in C Programming

## Overview

Sorting algorithms are fundamental algorithms that arrange elements in a specific order (ascending or descending). They are essential in computer science and are used in various applications like database management, data analysis, and algorithm design.

## Types of Sorting

### 1. **Comparison-Based Sorting**
Algorithms that compare elements to determine their relative order.

### 2. **Non-Comparison-Based Sorting**
Algorithms that use properties of the data rather than comparisons.

## Comparison-Based Sorting Algorithms

### 1. **Bubble Sort**

**Time Complexity**: O(n²)  
**Space Complexity**: O(1)  
**Stability**: Stable

```c
#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no swapping occurred, array is sorted
        if (!swapped) break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
```

### 2. **Selection Sort**

**Time Complexity**: O(n²)  
**Space Complexity**: O(1)  
**Stability**: Unstable

```c
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Find minimum element in unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap minimum element with first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
```

### 3. **Insertion Sort**

**Time Complexity**: O(n²)  
**Space Complexity**: O(1)  
**Stability**: Stable

```c
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

### 4. **Merge Sort**

**Time Complexity**: O(n log n)  
**Space Complexity**: O(n)  
**Stability**: Stable

```c
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
```

### 5. **Quick Sort**

**Time Complexity**: O(n log n) average, O(n²) worst case  
**Space Complexity**: O(log n)  
**Stability**: Unstable

```c
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        // Sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

### 6. **Heap Sort**

**Time Complexity**: O(n log n)  
**Space Complexity**: O(1)  
**Stability**: Unstable

```c
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
```

## Non-Comparison-Based Sorting

### 1. **Counting Sort**

**Time Complexity**: O(n + k)  
**Space Complexity**: O(k)  
**Stability**: Stable

```c
void countingSort(int arr[], int n) {
    // Find the maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Create count array
    int* count = (int*)calloc(max + 1, sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Store count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Store the output
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) {
        printf("Memory allocation failed\n");
        free(count);
        return;
    }
    
    // Find the index of each element in the output array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy the output array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    free(count);
    free(output);
}
```

### 2. **Radix Sort**

**Time Complexity**: O(d(n + k))  
**Space Complexity**: O(n + k)  
**Stability**: Stable

```c
void countingSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    
    // Store count of occurrences
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Change count[i] so that it contains position
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy the output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    // Find the maximum number to know number of digits
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}
```

## Comparison of Sorting Algorithms

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stable |
|-----------|-----------|--------------|------------|------------------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(k) | Yes |
| Radix Sort | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k) | Yes |

## When to Use Each Algorithm

### **Bubble Sort**
- Small datasets
- Educational purposes
- When simplicity is more important than efficiency

### **Selection Sort**
- Small datasets
- When memory writes are expensive

### **Insertion Sort**
- Small datasets
- Nearly sorted arrays
- Online sorting (sorting as data arrives)

### **Merge Sort**
- Large datasets
- When stability is required
- External sorting

### **Quick Sort**
- Large datasets
- When average-case performance is important
- In-place sorting preferred

### **Heap Sort**
- Large datasets
- When guaranteed O(n log n) is required
- In-place sorting

### **Counting Sort**
- When range of input data is not much larger than number of objects
- Integer sorting with known range

### **Radix Sort**
- Integer sorting
- String sorting
- When data has fixed number of digits

## Complete Example with All Algorithms

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function declarations
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);
void countingSort(int arr[], int n);
void radixSort(int arr[], int n);

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    int original[] = {64, 34, 25, 12, 22, 11, 90, 45, 78, 33};
    int n = sizeof(original) / sizeof(original[0]);
    int arr[n];
    
    printf("Original array: ");
    printArray(original, n);
    
    // Test Bubble Sort
    copyArray(original, arr, n);
    bubbleSort(arr, n);
    printf("Bubble Sort: ");
    printArray(arr, n);
    
    // Test Selection Sort
    copyArray(original, arr, n);
    selectionSort(arr, n);
    printf("Selection Sort: ");
    printArray(arr, n);
    
    // Test Insertion Sort
    copyArray(original, arr, n);
    insertionSort(arr, n);
    printf("Insertion Sort: ");
    printArray(arr, n);
    
    // Test Merge Sort
    copyArray(original, arr, n);
    mergeSort(arr, 0, n - 1);
    printf("Merge Sort: ");
    printArray(arr, n);
    
    // Test Quick Sort
    copyArray(original, arr, n);
    quickSort(arr, 0, n - 1);
    printf("Quick Sort: ");
    printArray(arr, n);
    
    // Test Heap Sort
    copyArray(original, arr, n);
    heapSort(arr, n);
    printf("Heap Sort: ");
    printArray(arr, n);
    
    // Test Counting Sort (for non-negative integers)
    copyArray(original, arr, n);
    countingSort(arr, n);
    printf("Counting Sort: ");
    printArray(arr, n);
    
    // Test Radix Sort
    copyArray(original, arr, n);
    radixSort(arr, n);
    printf("Radix Sort: ");
    printArray(arr, n);
    
    return 0;
}
```

### Output

```
Original array: 64 34 25 12 22 11 90 45 78 33 
Bubble Sort: 11 12 22 25 33 34 45 64 78 90 
Selection Sort: 11 12 22 25 33 34 45 64 78 90 
Insertion Sort: 11 12 22 25 33 34 45 64 78 90 
Merge Sort: 11 12 22 25 33 34 45 64 78 90 
Quick Sort: 11 12 22 25 33 34 45 64 78 90 
Heap Sort: 11 12 22 25 33 34 45 64 78 90 
Counting Sort: 11 12 22 25 33 34 45 64 78 90 
Radix Sort: 11 12 22 25 33 34 45 64 78 90 
```

## Applications of Sorting

1. **Database Management**: Indexing and query optimization
2. **Data Analysis**: Statistical analysis and reporting
3. **Search Algorithms**: Binary search requires sorted data
4. **File Systems**: Directory listings and file organization
5. **Graphics**: Z-buffer algorithms for 3D rendering
6. **Networking**: Packet routing and load balancing
7. **Machine Learning**: Feature scaling and data preprocessing 