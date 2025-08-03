# Dynamic Programming in C Programming

## Overview

Dynamic Programming (DP) is a method for solving complex problems by breaking them down into simpler subproblems. It is used when the solution to a problem depends on solutions to smaller instances of the same problem. DP is particularly useful for optimization problems.

## Key Concepts

### 1. **Optimal Substructure**
The optimal solution to a problem contains optimal solutions to its subproblems.

### 2. **Overlapping Subproblems**
The same subproblems are solved multiple times.

### 3. **Memoization**
Storing the results of expensive function calls and returning the cached result.

## Types of Dynamic Programming

### 1. **Top-Down (Memoization)**
Recursive approach with caching of results.

### 2. **Bottom-Up (Tabulation)**
Iterative approach building solutions from base cases.

## Classic Dynamic Programming Problems

### 1. **Fibonacci Numbers**

**Problem**: Calculate the nth Fibonacci number.

#### Recursive Solution (Inefficient)
```c
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

#### Top-Down DP (Memoization)
```c
#include <stdio.h>
#include <stdlib.h>

int fibonacciMemo(int n, int* memo) {
    if (n <= 1) {
        return n;
    }
    
    if (memo[n] != -1) {
        return memo[n];
    }
    
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

int fibonacciTopDown(int n) {
    int* memo = (int*)malloc((n + 1) * sizeof(int));
    if (memo == NULL) {
        return -1;
    }
    
    // Initialize memo array
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    int result = fibonacciMemo(n, memo);
    free(memo);
    return result;
}
```

#### Bottom-Up DP (Tabulation)
```c
int fibonacciBottomUp(int n) {
    if (n <= 1) {
        return n;
    }
    
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    if (dp == NULL) {
        return -1;
    }
    
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    int result = dp[n];
    free(dp);
    return result;
}
```

#### Space-Optimized Solution
```c
int fibonacciOptimized(int n) {
    if (n <= 1) {
        return n;
    }
    
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    
    return curr;
}
```

### 2. **Longest Common Subsequence (LCS)**

**Problem**: Find the length of the longest subsequence present in both strings.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(char* str1, char* str2, int m, int n) {
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    if (dp == NULL) {
        return -1;
    }
    
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)calloc(n + 1, sizeof(int));
        if (dp[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(dp[j]);
            }
            free(dp);
            return -1;
        }
    }
    
    // Build LCS matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    int result = dp[m][n];
    
    // Free memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

// Print the LCS
void printLCS(char* str1, char* str2, int m, int n) {
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    if (dp == NULL) return;
    
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)calloc(n + 1, sizeof(int));
        if (dp[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(dp[j]);
            }
            free(dp);
            return;
        }
    }
    
    // Build LCS matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Reconstruct LCS
    int index = dp[m][n];
    char* lcs = (char*)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';
    
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    printf("LCS: %s\n", lcs);
    
    free(lcs);
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
}
```

### 3. **Longest Increasing Subsequence (LIS)**

**Problem**: Find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

```c
int lis(int arr[], int n) {
    int* dp = (int*)malloc(n * sizeof(int));
    if (dp == NULL) {
        return -1;
    }
    
    // Initialize all values to 1
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    // Compute LIS values
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    // Find maximum LIS value
    int max = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    
    free(dp);
    return max;
}
```

### 4. **Edit Distance**

**Problem**: Find the minimum number of operations (insert, delete, replace) required to convert one string to another.

```c
int editDistance(char* str1, char* str2, int m, int n) {
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    if (dp == NULL) {
        return -1;
    }
    
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
        if (dp[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(dp[j]);
            }
            free(dp);
            return -1;
        }
    }
    
    // Fill dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            }
        }
    }
    
    int result = dp[m][n];
    
    // Free memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}
```

### 5. **0/1 Knapsack Problem**

**Problem**: Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value.

```c
int knapsack(int weights[], int values[], int n, int W) {
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    if (dp == NULL) {
        return -1;
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)calloc(W + 1, sizeof(int));
        if (dp[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(dp[j]);
            }
            free(dp);
            return -1;
        }
    }
    
    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    int result = dp[n][W];
    
    // Free memory
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
```

### 6. **Coin Change Problem**

**Problem**: Find the minimum number of coins required to make a given amount.

```c
int coinChange(int coins[], int n, int amount) {
    int* dp = (int*)malloc((amount + 1) * sizeof(int));
    if (dp == NULL) {
        return -1;
    }
    
    // Initialize dp array
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1; // Use amount + 1 as infinity
    }
    dp[0] = 0;
    
    // Fill dp array
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    int result = (dp[amount] > amount) ? -1 : dp[amount];
    free(dp);
    return result;
}
```

### 7. **Matrix Chain Multiplication**

**Problem**: Find the most efficient way to multiply a sequence of matrices.

```c
int matrixChainMultiplication(int dimensions[], int n) {
    int** dp = (int**)malloc(n * sizeof(int*));
    if (dp == NULL) {
        return -1;
    }
    
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
        if (dp[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(dp[j]);
            }
            free(dp);
            return -1;
        }
    }
    
    // Fill dp table
    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    
    int result = dp[1][n - 1];
    
    // Free memory
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
```

## Complete Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Function declarations
int fibonacciBottomUp(int n);
int lcs(char* str1, char* str2, int m, int n);
int lis(int arr[], int n);
int editDistance(char* str1, char* str2, int m, int n);
int knapsack(int weights[], int values[], int n, int W);
int coinChange(int coins[], int n, int amount);

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    printf("=== Dynamic Programming Examples ===\n\n");
    
    // Fibonacci
    printf("1. Fibonacci (n=10): %d\n", fibonacciBottomUp(10));
    
    // LCS
    char str1[] = "ABCDGH";
    char str2[] = "AEDFHR";
    printf("2. LCS of '%s' and '%s': %d\n", str1, str2, lcs(str1, str2, strlen(str1), strlen(str2)));
    
    // LIS
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("3. LIS length: %d\n", lis(arr, n));
    
    // Edit Distance
    char s1[] = "saturday";
    char s2[] = "sunday";
    printf("4. Edit distance between '%s' and '%s': %d\n", s1, s2, editDistance(s1, s2, strlen(s1), strlen(s2)));
    
    // Knapsack
    int weights[] = {2, 1, 3, 2};
    int values[] = {12, 10, 20, 15};
    int W = 5;
    printf("5. Knapsack (W=%d): %d\n", W, knapsack(weights, values, 4, W));
    
    // Coin Change
    int coins[] = {1, 2, 5};
    int amount = 11;
    printf("6. Coin change for amount %d: %d coins\n", amount, coinChange(coins, 3, amount));
    
    return 0;
}
```

## Optimization Techniques

### 1. **Space Optimization**
Many DP problems can be optimized to use less space.

### 2. **State Compression**
For problems with small state spaces, use bit manipulation.

### 3. **Sliding Window**
For problems where only recent states matter.

## When to Use Dynamic Programming

1. **Optimization Problems**: Finding minimum/maximum values
2. **Counting Problems**: Finding number of ways to do something
3. **Decision Problems**: Yes/no questions with optimal substructure
4. **Sequence Problems**: Working with arrays/strings
5. **Tree/Graph Problems**: Path finding, tree traversal

## Common DP Patterns

1. **1D DP**: Fibonacci, LIS, Coin Change
2. **2D DP**: LCS, Edit Distance, Matrix Chain
3. **Tree DP**: Tree traversal with state
4. **Digit DP**: Number problems
5. **Bitmask DP**: Subset problems

## Applications of Dynamic Programming

1. **Bioinformatics**: Sequence alignment
2. **Natural Language Processing**: Spell checking
3. **Computer Graphics**: Image processing
4. **Game Development**: AI pathfinding
5. **Finance**: Portfolio optimization
6. **Operations Research**: Resource allocation
7. **Machine Learning**: Sequence modeling 