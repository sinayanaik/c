# Continue Statement in C Programming

## Overview

The `continue` statement is used to skip the rest of the current iteration in a loop and move to the next iteration. Unlike `break`, it doesn't terminate the loop but skips the remaining statements in the current iteration.

## Syntax

```c
continue;
```

## Usage in Different Loops

### 1. **Continue in While Loop**

```c
#include <stdio.h>

int main() {
    int i = 1;
    
    while (i <= 10) {
        if (i == 5) {
            i++;  // Important: increment before continue
            continue;  // Skip printing when i equals 5
        }
        printf("%d ", i);
        i++;
    }
    printf("\nLoop completed\n");
    
    return 0;
}
```

### 2. **Continue in For Loop**

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 10; i++) {
        if (i == 3 || i == 7) {
            continue;  // Skip printing 3 and 7
        }
        printf("%d ", i);
    }
    printf("\nLoop completed\n");
    
    return 0;
}
```

### 3. **Continue in Do-While Loop**

```c
#include <stdio.h>

int main() {
    int num = 1;
    
    do {
        if (num % 2 == 0) {
            num++;
            continue;  // Skip even numbers
        }
        printf("%d ", num);
        num++;
    } while (num <= 10);
    
    printf("\nLoop completed\n");
    return 0;
}
```

## Common Use Cases

### 1. **Skipping Invalid Data**

```c
#include <stdio.h>

int main() {
    int numbers[] = {1, -5, 3, 0, 8, -2, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] <= 0) {
            continue;  // Skip non-positive numbers
        }
        sum += numbers[i];
        printf("Added %d, sum = %d\n", numbers[i], sum);
    }
    
    printf("Final sum: %d\n", sum);
    return 0;
}
```

### 2. **Input Validation**

```c
#include <stdio.h>

int main() {
    int count = 0;
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        int num;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        
        if (num < 0) {
            printf("Negative number ignored\n");
            continue;  // Skip negative numbers
        }
        
        if (num > 100) {
            printf("Number too large, ignored\n");
            continue;  // Skip numbers > 100
        }
        
        sum += num;
        count++;
    }
    
    if (count > 0) {
        printf("Average: %.2f\n", (float)sum / count);
    } else {
        printf("No valid numbers entered\n");
    }
    
    return 0;
}
```

### 3. **Processing Specific Elements**

```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[] = "Hello123World!";
    
    printf("Letters only: ");
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            continue;  // Skip non-letters
        }
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Nested Loops and Continue

### Continue in Inner Loop

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 3; i++) {
        printf("Outer loop iteration %d:\n", i);
        
        for (int j = 1; j <= 5; j++) {
            if (j == 3) {
                continue;  // Skip inner loop iteration when j == 3
            }
            printf("  Inner loop: %d\n", j);
        }
        
        printf("Outer loop continues\n");
    }
    
    return 0;
}
```

### Continue in Outer Loop

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;  // Skip outer loop iteration when i == 3
        }
        
        printf("Processing row %d:\n", i);
        for (int j = 1; j <= 3; j++) {
            printf("  Column %d\n", j);
        }
    }
    
    return 0;
}
```

## Advanced Patterns

### 1. **Error Handling with Continue**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arrays[5];
    
    for (int i = 0; i < 5; i++) {
        arrays[i] = malloc(10 * sizeof(int));
        
        if (arrays[i] == NULL) {
            printf("Memory allocation failed for array %d\n", i);
            continue;  // Skip processing this array
        }
        
        // Process array
        for (int j = 0; j < 10; j++) {
            arrays[i][j] = i * 10 + j;
        }
        
        printf("Array %d processed successfully\n", i);
    }
    
    // Cleanup
    for (int i = 0; i < 5; i++) {
        if (arrays[i] != NULL) {
            free(arrays[i]);
        }
    }
    
    return 0;
}
```

### 2. **Conditional Processing**

```c
#include <stdio.h>

int main() {
    int numbers[] = {15, 25, 35, 45, 55, 65, 75, 85, 95};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Numbers divisible by 5 but not by 3:\n");
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 5 != 0) {
            continue;  // Skip if not divisible by 5
        }
        
        if (numbers[i] % 3 == 0) {
            continue;  // Skip if divisible by 3
        }
        
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
```

### 3. **Data Filtering**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char* words[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int count = sizeof(words) / sizeof(words[0]);
    
    printf("Words starting with 'a' or 'e':\n");
    for (int i = 0; i < count; i++) {
        char first = words[i][0];
        if (first != 'a' && first != 'e') {
            continue;  // Skip words not starting with 'a' or 'e'
        }
        printf("%s ", words[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Performance Considerations

### 1. **Early Skip for Efficiency**

```c
#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int expensive_operations = 0;
    
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            continue;  // Skip even numbers early
        }
        
        // Expensive operation only for odd numbers
        expensive_operations++;
        printf("Processing odd number: %d\n", numbers[i]);
    }
    
    printf("Expensive operations performed: %d\n", expensive_operations);
    return 0;
}
```

### 2. **Conditional Function Calls**

```c
#include <stdio.h>

void processNumber(int num) {
    printf("Processing: %d\n", num);
    // Expensive processing here
}

int main() {
    int values[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < size; i++) {
        if (values[i] < 50) {
            continue;  // Skip small values
        }
        
        if (values[i] > 80) {
            continue;  // Skip large values
        }
        
        processNumber(values[i]);  // Only process values 50-80
    }
    
    return 0;
}
```

## Common Patterns

### 1. **Menu Processing**

```c
#include <stdio.h>

int main() {
    int choice;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Option 1\n");
        printf("2. Option 2\n");
        printf("3. Option 3\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;  // Exit program
        }
        
        if (choice < 1 || choice > 3) {
            printf("Invalid choice\n");
            continue;  // Skip to next iteration
        }
        
        // Process valid choice
        printf("Processing option %d\n", choice);
    }
    
    return 0;
}
```

### 2. **Data Validation Loop**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int attempts = 0;
    
    while (attempts < 3) {
        printf("Enter password: ");
        scanf("%s", password);
        
        if (strlen(password) < 6) {
            printf("Password too short\n");
            attempts++;
            continue;
        }
        
        if (strlen(password) > 20) {
            printf("Password too long\n");
            attempts++;
            continue;
        }
        
        // Password is valid
        printf("Password accepted\n");
        break;
    }
    
    if (attempts >= 3) {
        printf("Too many attempts\n");
    }
    
    return 0;
}
```

## Best Practices

### 1. **Use Continue for Cleaner Code**

```c
// Good: Use continue for early skip
for (int i = 0; i < n; i++) {
    if (condition) {
        continue;  // Skip this iteration
    }
    // Process element
}

// Bad: Use nested if
for (int i = 0; i < n; i++) {
    if (!condition) {
        // Process element
    }
}
```

### 2. **Update Loop Variables Before Continue**

```c
// Good: Update before continue
while (i < n) {
    if (condition) {
        i++;  // Update before continue
        continue;
    }
    // Process element
    i++;
}

// Bad: Missing update
while (i < n) {
    if (condition) {
        continue;  // i never gets updated
    }
    // Process element
    i++;
}
```

### 3. **Use Continue for Error Handling**

```c
for (int i = 0; i < count; i++) {
    if (data[i] == NULL) {
        printf("Skipping null data at index %d\n", i);
        continue;  // Skip null data
    }
    
    if (data[i]->isValid == 0) {
        printf("Skipping invalid data at index %d\n", i);
        continue;  // Skip invalid data
    }
    
    // Process valid data
    processData(data[i]);
}
```

## Common Mistakes

### 1. **Infinite Loop with Continue**

```c
#include <stdio.h>

int main() {
    int i = 0;
    
    while (i < 10) {
        if (i == 5) {
            continue;  // i never gets incremented
        }
        printf("%d ", i);
        i++;  // This line is never reached when i == 5
    }
    
    return 0;
}
```

### 2. **Continue Outside Loop**

```c
// Error: continue outside loop
int main() {
    continue;  // Compilation error
    return 0;
}
```

### 3. **Missing Loop Variable Update**

```c
#include <stdio.h>

int main() {
    int i = 0;
    
    while (i < 5) {
        if (i == 2) {
            continue;  // i stays 2 forever
        }
        printf("%d ", i);
        i++;
    }
    
    return 0;
}
```

## Summary

**Key Points:**
- `continue` skips the rest of the current iteration
- `continue` moves to the next iteration of the loop
- Update loop variables before `continue` in while/do-while loops
- `continue` only affects the innermost loop in nested loops
- Use `continue` for cleaner, more readable code

**Best Practices:**
- Use `continue` for early skip in loops
- Update loop variables before `continue`
- Use `continue` for error handling and validation
- Avoid infinite loops with `continue`
- Test `continue` behavior thoroughly

**Common Use Cases:**
- Skipping invalid or unwanted data
- Input validation
- Error handling in loops
- Conditional processing
- Data filtering
- Menu processing 