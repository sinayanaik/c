# String Manipulation - Interview Questions & Answers

## 🎯 Overview
String manipulation is a common topic in C programming interviews. This guide covers string basics, common functions, memory management, and practical examples.

## 📚 Core Concepts

### String Basics
In C, strings are arrays of characters terminated by a null character ('\0').

```c
char str[] = "Hello";  // Automatically adds '\0'
char str2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

## 🎯 Interview Questions & Answers

### Q1: What is a string in C and how is it stored?
**Answer:**
A string in C is an array of characters terminated by a null character ('\0'). It's stored as a contiguous block of memory.

**Example:**
```c
#include <stdio.h>

int main() {
    char str[] = "Hello";
    
    printf("String: %s\n", str);
    printf("Length: %zu\n", strlen(str));
    printf("Size: %zu\n", sizeof(str));  // Includes '\0'
    
    // Print each character including null terminator
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == '\0') {
            printf("str[%d] = '\\0'\n", i);
        } else {
            printf("str[%d] = '%c'\n", i, str[i]);
        }
    }
    
    return 0;
}
```

### Q2: Implement strlen() function
**Answer:**
```c
#include <stdio.h>

int myStrlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Alternative using pointer arithmetic
int myStrlen2(const char *str) {
    const char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

int main() {
    char str[] = "Hello World";
    printf("Length: %d\n", myStrlen(str));
    printf("Length: %d\n", myStrlen2(str));
    return 0;
}
```

### Q3: Implement strcpy() function
**Answer:**
```c
#include <stdio.h>

void myStrcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Don't forget null terminator
}

// Alternative using pointer arithmetic
void myStrcpy2(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char dest[20];
    char src[] = "Hello World";
    
    myStrcpy(dest, src);
    printf("Copied string: %s\n", dest);
    
    return 0;
}
```

### Q4: Implement strcmp() function
**Answer:**
```c
#include <stdio.h>

int myStrcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
    }
    
    // Check if both strings ended
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;
    } else if (*str1 == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    
    printf("str1 vs str2: %d\n", myStrcmp(str1, str2));
    printf("str1 vs str3: %d\n", myStrcmp(str1, str3));
    printf("str3 vs str1: %d\n", myStrcmp(str3, str1));
    
    return 0;
}
```

### Q5: Implement strcat() function
**Answer:**
```c
#include <stdio.h>

void myStrcat(char *dest, const char *src) {
    // Find end of destination string
    while (*dest != '\0') {
        dest++;
    }
    
    // Copy source string to end of destination
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char dest[20] = "Hello";
    char src[] = " World";
    
    myStrcat(dest, src);
    printf("Concatenated: %s\n", dest);
    
    return 0;
}
```

### Q6: Check if a string is palindrome
**Answer:**
```c
#include <stdio.h>
#include <string.h>

int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;  // Not palindrome
        }
        left++;
        right--;
    }
    return 1;  // Is palindrome
}

int main() {
    char str1[] = "racecar";
    char str2[] = "hello";
    char str3[] = "anna";
    
    printf("'%s' is palindrome: %s\n", str1, isPalindrome(str1) ? "Yes" : "No");
    printf("'%s' is palindrome: %s\n", str2, isPalindrome(str2) ? "Yes" : "No");
    printf("'%s' is palindrome: %s\n", str3, isPalindrome(str3) ? "Yes" : "No");
    
    return 0;
}
```

### Q7: Reverse a string
**Answer:**
```c
#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        // Swap characters
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        
        left++;
        right--;
    }
}

int main() {
    char str[] = "Hello World";
    printf("Original: %s\n", str);
    
    reverseString(str);
    printf("Reversed: %s\n", str);
    
    return 0;
}
```

### Q8: Count vowels and consonants
**Answer:**
```c
#include <stdio.h>
#include <ctype.h>

void countVowelsConsonants(const char *str, int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    
    while (*str != '\0') {
        char c = tolower(*str);
        
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
        str++;
    }
}

int main() {
    char str[] = "Hello World";
    int vowels, consonants;
    
    countVowelsConsonants(str, &vowels, &consonants);
    printf("String: %s\n", str);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    
    return 0;
}
```

## 🚨 Common String Issues

### 1. Buffer Overflow
```c
#include <stdio.h>
#include <string.h>

void bufferOverflow() {
    char buffer[5];
    strcpy(buffer, "This is too long");  // Buffer overflow!
    printf("%s\n", buffer);
}
```

### 2. Missing Null Terminator
```c
#include <stdio.h>

void missingNullTerminator() {
    char str[5] = {'H', 'e', 'l', 'l', 'o'};  // No '\0'
    printf("%s\n", str);  // Undefined behavior
}
```

### 3. String Literal Modification
```c
#include <stdio.h>

void modifyStringLiteral() {
    char *str = "Hello";  // String literal (read-only)
    str[0] = 'h';         // Undefined behavior - segmentation fault
}
```

## 🎯 Practice Questions

### Question 1: What will be the output?
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello";
    printf("Length: %zu\n", strlen(str));
    printf("Size: %zu\n", sizeof(str));
    return 0;
}
```

**Answer:** Length: 5, Size: 6

### Question 2: What will be the output?
```c
#include <stdio.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    
    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strcmp(str1, str3));
    printf("%d\n", strcmp(str3, str1));
    return 0;
}
```

**Answer:** 0, -1, 1

### Question 3: What's wrong with this code?
```c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[5];
    char src[] = "Hello World";
    strcpy(dest, src);
    printf("%s\n", dest);
    return 0;
}
```

**Answer:** Buffer overflow - dest is too small for src

## 🏆 Best Practices

### 1. Always Check Buffer Size
```c
#include <stdio.h>
#include <string.h>

void safeStringCopy(char *dest, const char *src, size_t destSize) {
    strncpy(dest, src, destSize - 1);
    dest[destSize - 1] = '\0';
}
```

### 2. Use const for String Parameters
```c
void processString(const char *str) {
    // str cannot be modified
}
```

### 3. Handle Memory Properly
```c
char *str = malloc(10);
if (str != NULL) {
    strcpy(str, "Hello");
    // Use str
    free(str);
}
```

### 4. Use String Library Functions Safely
```c
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    char *source = "This is a very long string";
    
    // Safe string copy
    if (strlen(source) < sizeof(buffer)) {
        strcpy(buffer, source);
    } else {
        strncpy(buffer, source, sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';
    }
    
    return 0;
}
```

## 📚 Additional Resources

- [String Functions](./02_string_functions.md)
- [String Algorithms](./03_string_algorithms.md)
- [Memory Management in Strings](./04_string_memory.md)
- [Advanced String Topics](./05_advanced_strings.md)

---

**Next: [String Functions](./02_string_functions.md)** 