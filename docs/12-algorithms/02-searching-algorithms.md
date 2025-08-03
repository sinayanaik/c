# Searching Algorithms in C Programming

## Overview

Searching algorithms are fundamental algorithms used to find specific elements within a data structure. They are essential in computer science and are used in various applications like database queries, web search engines, and data analysis.

## Types of Searching

### 1. **Linear Search**
Sequentially checks each element until the target is found.

### 2. **Binary Search**
Efficiently searches sorted arrays by dividing the search space in half.

### 3. **Hashing**
Uses hash functions to map data to specific locations for quick access.

## Linear Search

**Time Complexity**: O(n)  
**Space Complexity**: O(1)

```c
#include <stdio.h>

// Linear search function
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Linear search with multiple occurrences
void linearSearchAll(int arr[], int n, int target) {
    printf("Found at indices: ");
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("%d ", i);
            found = true;
        }
    }
    
    if (!found) {
        printf("Not found");
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 45, 78, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;
    
    int result = linearSearch(arr, n, target);
    
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }
    
    return 0;
}
```

## Binary Search

**Time Complexity**: O(log n)  
**Space Complexity**: O(1)  
**Requirement**: Array must be sorted

### Iterative Binary Search

```c
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // If target is found at mid, return it
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    // Target not found
    return -1;
}
```

### Recursive Binary Search

```c
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        // If target is found at mid, return it
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, search right half
        if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target);
        }
        
        // If target is smaller, search left half
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
    
    // Target not found
    return -1;
}
```

### Binary Search for First Occurrence

```c
int binarySearchFirst(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching left half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### Binary Search for Last Occurrence

```c
int binarySearchLast(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}
```

### Binary Search for Count of Occurrences

```c
int countOccurrences(int arr[], int n, int target) {
    int first = binarySearchFirst(arr, n, target);
    
    if (first == -1) {
        return 0; // Target not found
    }
    
    int last = binarySearchLast(arr, n, target);
    
    return last - first + 1;
}
```

## Jump Search

**Time Complexity**: O(√n)  
**Space Complexity**: O(1)  
**Requirement**: Array must be sorted

```c
#include <math.h>

int jumpSearch(int arr[], int n, int target) {
    // Finding block size to be jumped
    int step = sqrt(n);
    
    // Finding the block where element is present (if it is present)
    int prev = 0;
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    
    // Doing a linear search for target in block beginning with prev
    while (prev < min(step, n)) {
        if (arr[prev] == target) {
            return prev;
        }
        prev++;
    }
    
    return -1;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}
```

## Interpolation Search

**Time Complexity**: O(log log n) average, O(n) worst case  
**Space Complexity**: O(1)  
**Requirement**: Array must be sorted and uniformly distributed

```c
int interpolationSearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        // Avoid division by zero
        if (left == right) {
            if (arr[left] == target) {
                return left;
            }
            return -1;
        }
        
        // Probing the position with keeping uniform distribution in mind
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));
        
        if (arr[pos] == target) {
            return pos;
        }
        
        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    
    return -1;
}
```

## Exponential Search

**Time Complexity**: O(log n)  
**Space Complexity**: O(1)  
**Requirement**: Array must be sorted

```c
int exponentialSearch(int arr[], int n, int target) {
    // If array is empty
    if (n == 0) {
        return -1;
    }
    
    // If target is the first element
    if (arr[0] == target) {
        return 0;
    }
    
    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= target) {
        i = i * 2;
    }
    
    // Call binary search for the found range
    return binarySearchRecursive(arr, i / 2, min(i, n - 1), target);
}
```

## Fibonacci Search

**Time Complexity**: O(log n)  
**Space Complexity**: O(1)  
**Requirement**: Array must be sorted

```c
int fibonacciSearch(int arr[], int n, int target) {
    // Initialize fibonacci numbers
    int fibMMm2 = 0;   // (m-2)'th Fibonacci number
    int fibMMm1 = 1;   // (m-1)'th Fibonacci number
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci number
    
    // fibM is going to store the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    
    // Initialize the offset as -1
    int offset = -1;
    
    // While there are elements to be inspected
    while (fibM > 1) {
        // Check if fibMm2 is a valid location
        int i = min(offset + fibMMm2, n - 1);
        
        // If target is greater than the value at index i, cut the subarray from offset to i
        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        // If target is less than the value at index i, cut the subarray after i+1
        else if (arr[i] > target) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        // Element found
        else {
            return i;
        }
    }
    
    // Compare the last element
    if (fibMMm1 && offset < n - 1 && arr[offset + 1] == target) {
        return offset + 1;
    }
    
    return -1;
}
```

## Hashing for Searching

**Time Complexity**: O(1) average, O(n) worst case  
**Space Complexity**: O(n)

### Simple Hash Table Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct {
    int key;
    int value;
    bool occupied;
} HashEntry;

typedef struct {
    HashEntry* table;
    int size;
} HashTable;

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Create hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) {
        return NULL;
    }
    
    ht->table = (HashEntry*)calloc(TABLE_SIZE, sizeof(HashEntry));
    if (ht->table == NULL) {
        free(ht);
        return NULL;
    }
    
    ht->size = TABLE_SIZE;
    return ht;
}

// Insert into hash table
void insert(HashTable* ht, int key, int value) {
    int index = hash(key);
    int originalIndex = index;
    
    // Linear probing for collision resolution
    do {
        if (!ht->table[index].occupied) {
            ht->table[index].key = key;
            ht->table[index].value = value;
            ht->table[index].occupied = true;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != originalIndex);
    
    printf("Hash table is full\n");
}

// Search in hash table
int search(HashTable* ht, int key) {
    int index = hash(key);
    int originalIndex = index;
    
    do {
        if (ht->table[index].occupied && ht->table[index].key == key) {
            return ht->table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != originalIndex && ht->table[index].occupied);
    
    return -1; // Not found
}

// Delete from hash table
void delete(HashTable* ht, int key) {
    int index = hash(key);
    int originalIndex = index;
    
    do {
        if (ht->table[index].occupied && ht->table[index].key == key) {
            ht->table[index].occupied = false;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != originalIndex && ht->table[index].occupied);
}

// Free hash table
void freeHashTable(HashTable* ht) {
    if (ht != NULL) {
        free(ht->table);
        free(ht);
    }
}
```

## String Searching Algorithms

### 1. **Naive String Search**

```c
int naiveStringSearch(char* text, char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    
    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            return i; // Pattern found at index i
        }
    }
    return -1; // Pattern not found
}
```

### 2. **KMP (Knuth-Morris-Pratt) Algorithm**

```c
void computeLPSArray(char* pattern, int* lps, int patternLen) {
    int len = 0;
    lps[0] = 0;
    
    int i = 1;
    while (i < patternLen) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(char* text, char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    
    int* lps = (int*)malloc(patternLen * sizeof(int));
    if (lps == NULL) {
        return -1;
    }
    
    computeLPSArray(pattern, lps, patternLen);
    
    int i = 0; // Index for text
    int j = 0; // Index for pattern
    
    while (i < textLen) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        
        if (j == patternLen) {
            free(lps);
            return i - j; // Pattern found
        } else if (i < textLen && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    free(lps);
    return -1; // Pattern not found
}
```

## Complete Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Function declarations
int linearSearch(int arr[], int n, int target);
int binarySearch(int arr[], int n, int target);
int binarySearchRecursive(int arr[], int left, int right, int target);
int jumpSearch(int arr[], int n, int target);
int interpolationSearch(int arr[], int n, int target);
int exponentialSearch(int arr[], int n, int target);
int fibonacciSearch(int arr[], int n, int target);

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    printf("Array: ");
    printArray(arr, n);
    printf("Searching for: %d\n\n", target);
    
    // Linear Search
    int result = linearSearch(arr, n, target);
    printf("Linear Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Binary Search
    result = binarySearch(arr, n, target);
    printf("Binary Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Jump Search
    result = jumpSearch(arr, n, target);
    printf("Jump Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Interpolation Search
    result = interpolationSearch(arr, n, target);
    printf("Interpolation Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Exponential Search
    result = exponentialSearch(arr, n, target);
    printf("Exponential Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    // Fibonacci Search
    result = fibonacciSearch(arr, n, target);
    printf("Fibonacci Search: ");
    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }
    
    return 0;
}
```

## Comparison of Searching Algorithms

| Algorithm | Time Complexity | Space Complexity | Requirements |
|-----------|----------------|------------------|--------------|
| Linear Search | O(n) | O(1) | None |
| Binary Search | O(log n) | O(1) | Sorted array |
| Jump Search | O(√n) | O(1) | Sorted array |
| Interpolation Search | O(log log n) | O(1) | Sorted, uniform distribution |
| Exponential Search | O(log n) | O(1) | Sorted array |
| Fibonacci Search | O(log n) | O(1) | Sorted array |
| Hash Table | O(1) average | O(n) | None |

## When to Use Each Algorithm

### **Linear Search**
- Small datasets
- Unsorted arrays
- When simplicity is important

### **Binary Search**
- Large sorted datasets
- When logarithmic time complexity is needed
- Database indexing

### **Jump Search**
- Sorted arrays
- When binary search is too complex
- Jumping through elements

### **Interpolation Search**
- Sorted arrays with uniform distribution
- When data is evenly distributed
- Better than binary search for uniform data

### **Exponential Search**
- Sorted arrays
- When target is closer to the beginning
- Bounded arrays

### **Fibonacci Search**
- Sorted arrays
- When division operations are expensive
- Alternative to binary search

### **Hash Table**
- When constant time access is needed
- When memory is not a constraint
- Database lookups

## Applications of Searching

1. **Database Systems**: Indexing and querying
2. **Web Search Engines**: Finding relevant pages
3. **File Systems**: Locating files and directories
4. **Text Processing**: Pattern matching in documents
5. **Network Routing**: Finding optimal paths
6. **Game AI**: Pathfinding and decision making
7. **Data Analysis**: Finding specific data points 