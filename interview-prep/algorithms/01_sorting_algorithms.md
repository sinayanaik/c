# Sorting Algorithms - Interview Questions & Answers

## 🎯 Overview
Sorting algorithms are fundamental to computer science and are frequently tested in interviews. This guide covers common sorting algorithms with implementations, time complexity, and practical examples.

## 📚 Algorithm Complexity Summary

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stable |
|-----------|-----------|--------------|------------|------------------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |

## 🎯 Interview Questions & Answers

### Q1: Implement Bubble Sort
**Answer:**
```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no swapping occurred, array is sorted
        if (swapped == 0) {
            break;
        }
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

### Q2: Implement Selection Sort
**Answer:**
```c
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        // Find minimum element in unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap minimum element with first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
```

### Q3: Implement Insertion Sort
**Answer:**
```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
```

### Q4: Implement Merge Sort
**Answer:**
```c
#include <stdio.h>

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

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
```

### Q5: Implement Quick Sort
**Answer:**
```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
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

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
```

## 🎯 Advanced Questions

### Q6: What is the difference between stable and unstable sorting?
**Answer:**
A stable sorting algorithm maintains the relative order of equal elements, while an unstable algorithm may change their order.

**Example:**
```c
#include <stdio.h>

typedef struct {
    int value;
    int original_index;
} Element;

void stableSort(Element arr[], int n) {
    // Bubble sort (stable)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                Element temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    Element arr[] = {{3, 0}, {1, 1}, {3, 2}, {2, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original: ");
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) ", arr[i].value, arr[i].original_index);
    }
    printf("\n");
    
    stableSort(arr, n);
    
    printf("Sorted: ");
    for (int i = 0; i < n; i++) {
        printf("(%d,%d) ", arr[i].value, arr[i].original_index);
    }
    printf("\n");
    
    return 0;
}
```

### Q7: Implement counting sort for integers
**Answer:**
```c
#include <stdio.h>

void countingSort(int arr[], int n) {
    int output[n];
    int count[256] = {0};  // Assuming range 0-255
    
    // Count occurrences
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Modify count to store actual positions
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 1, 4, 1, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    countingSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
```

## 🎯 Practice Questions

### Question 1: What is the time complexity of bubble sort?
**Answer:** O(n²) in worst and average case, O(n) in best case

### Question 2: Which sorting algorithm is best for small arrays?
**Answer:** Insertion sort - it's simple, stable, and efficient for small datasets

### Question 3: What is the space complexity of merge sort?
**Answer:** O(n) - it requires additional space proportional to the input size

### Question 4: When would you use quick sort over merge sort?
**Answer:** Quick sort is better when:
- Memory is limited (in-place sorting)
- Cache performance is important
- Average case performance is more important than worst case

## 🏆 Key Takeaways

1. **Bubble Sort**: Simple but inefficient, good for educational purposes
2. **Selection Sort**: Simple, in-place, but inefficient
3. **Insertion Sort**: Good for small arrays, adaptive, stable
4. **Merge Sort**: Guaranteed O(n log n), stable, but requires extra space
5. **Quick Sort**: Usually fastest in practice, in-place, but not stable
6. **Counting Sort**: Linear time for small range integers

## 📚 Additional Resources

- [Searching Algorithms](./02_searching_algorithms.md)
- [Recursion](./03_recursion.md)
- [Dynamic Programming](./04_dynamic_programming.md)
- [Data Structures](./05_data_structures.md)

---

**Next: [Searching Algorithms](./02_searching_algorithms.md)** 