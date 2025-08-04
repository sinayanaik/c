# String Handling in C Programming

## Overview

In C, strings are arrays of characters terminated by a null character (`'\0'`). String handling involves various operations like copying, concatenation, comparison, and manipulation of character arrays.

## String Basics

### String Declaration

```c
#include <stdio.h>

int main() {
    // Method 1: Character array with null terminator
    char str1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    // Method 2: String literal (automatically adds '\0')
    char str2[] = "Hello";
    
    // Method 3: Fixed size array
    char str3[10] = "Hello";
    
    // Method 4: Pointer to string literal
    char* str4 = "Hello";
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    printf("str4: %s\n", str4);
    
    return 0;
}
```

**Output:**
```
str1: Hello
str2: Hello
str3: Hello
str4: Hello
```

### String Length

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello World";
    
    // Using strlen function
    int len1 = strlen(str);
    printf("Length using strlen: %d\n", len1);
    
    // Manual calculation
    int len2 = 0;
    while (str[len2] != '\0') {
        len2++;
    }
    printf("Length manually: %d\n", len2);
    
    return 0;
}
```

**Output:**
```
Length using strlen: 11
Length manually: 11
```

## String Library Functions

### 1. **strcpy() - String Copy**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello World";
    char destination[20];
    
    // Copy string
    strcpy(destination, source);
    printf("Copied string: %s\n", destination);
    
    // Safe copy with length limit
    char dest2[5];
    strncpy(dest2, source, 4);
    dest2[4] = '\0';  // Ensure null termination
    printf("Safe copy: %s\n", dest2);
    
    return 0;
}
```

**Output:**
```
Copied string: Hello World
Safe copy: Hell
```

### 2. **strcat() - String Concatenation**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[] = " World";
    
    // Concatenate strings
    strcat(str1, str2);
    printf("Concatenated: %s\n", str1);
    
    // Safe concatenation
    char str3[10] = "Hello";
    char str4[] = " World";
    strncat(str3, str4, 3);  // Only concatenate first 3 characters
    printf("Safe concatenation: %s\n", str3);
    
    return 0;
}
```

**Output:**
```
Concatenated: Hello World
Safe concatenation: Hello Wo
```

### 3. **strcmp() - String Comparison**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "apple";
    char str2[] = "apple";
    char str3[] = "banana";
    
    // Compare strings
    int result1 = strcmp(str1, str2);
    int result2 = strcmp(str1, str3);
    int result3 = strcmp(str3, str1);
    
    printf("str1 vs str2: %d\n", result1);  // 0 (equal)
    printf("str1 vs str3: %d\n", result2);  // negative (str1 < str3)
    printf("str3 vs str1: %d\n", result3);  // positive (str3 > str1)
    
    return 0;
}
```

**Output:**
```
str1 vs str2: 0
str1 vs str3: -1
str3 vs str1: 1
```

### 4. **strchr() - Find Character in String**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello World";
    char ch = 'o';
    
    // Find first occurrence
    char* result = strchr(str, ch);
    
    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", ch, result - str);
    } else {
        printf("Character '%c' not found\n", ch);
    }
    
    return 0;
}
```

**Output:**
```
Character 'o' found at position: 4
```

### 5. **strstr() - Find Substring**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello World";
    char substr[] = "World";
    
    // Find substring
    char* result = strstr(str, substr);
    
    if (result != NULL) {
        printf("Substring '%s' found at position: %ld\n", substr, result - str);
    } else {
        printf("Substring '%s' not found\n", substr);
    }
    
    return 0;
}
```

**Output:**
```
Substring 'World' found at position: 6
```

## String Manipulation

### 1. **String Reverse**

```c
#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    int length = strlen(str);
    int left = 0;
    int right = length - 1;
    
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
    char str[] = "Hello";
    printf("Original: %s\n", str);
    
    reverseString(str);
    printf("Reversed: %s\n", str);
    
    return 0;
}
```

**Output:**
```
Original: Hello
Reversed: olleH
```

### 2. **String to Uppercase/Lowercase**

```c
#include <stdio.h>
#include <ctype.h>

void toUpperCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void toLowerCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char str[] = "Hello World";
    
    printf("Original: %s\n", str);
    
    toUpperCase(str);
    printf("Uppercase: %s\n", str);
    
    toLowerCase(str);
    printf("Lowercase: %s\n", str);
    
    return 0;
}
```

**Output:**
```
Original: Hello World
Uppercase: HELLO WORLD
Lowercase: hello world
```

### 3. **Count Characters**

```c
#include <stdio.h>
#include <ctype.h>

void countCharacters(const char* str) {
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } else if (isalpha(ch)) {
            consonants++;
        } else if (isdigit(str[i])) {
            digits++;
        } else if (isspace(str[i])) {
            spaces++;
        }
    }
    
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
}

int main() {
    char str[] = "Hello World 123";
    countCharacters(str);
    
    return 0;
}
```

**Output:**
```
Vowels: 3
Consonants: 7
Digits: 3
Spaces: 2
```

## String Tokenization

### Using strtok()

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "apple,banana,cherry,date";
    char* token;
    
    // Get first token
    token = strtok(str, ",");
    
    // Get remaining tokens
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }
    
    return 0;
}
```

**Output:**
```
Token: apple
Token: banana
Token: cherry
Token: date
```

### Manual Tokenization

```c
#include <stdio.h>
#include <string.h>

void tokenizeString(const char* str, char delimiter) {
    char* temp = strdup(str);  // Create a copy
    char* token = temp;
    char* end = temp;
    
    while (*end) {
        if (*end == delimiter) {
            *end = '\0';
            printf("Token: %s\n", token);
            token = end + 1;
        }
        end++;
    }
    
    if (*token) {
        printf("Token: %s\n", token);
    }
    
    free(temp);
}

int main() {
    char str[] = "Hello:World:How:Are:You";
    tokenizeString(str, ':');
    
    return 0;
}
```

## String Validation

### 1. **Palindrome Check**

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char* str) {
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;
        
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;  // Not palindrome
        }
        
        left++;
        right--;
    }
    
    return 1;  // Is palindrome
}

int main() {
    char str[] = "A man a plan a canal Panama";
    
    if (isPalindrome(str)) {
        printf("'%s' is a palindrome\n", str);
    } else {
        printf("'%s' is not a palindrome\n", str);
    }
    
    return 0;
}
```

**Output:**
```
'A man a plan a canal Panama' is a palindrome
```

### 2. **Anagram Check**

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isAnagram(const char* str1, const char* str2) {
    int count[256] = {0};
    
    // Count characters in first string
    for (int i = 0; str1[i] != '\0'; i++) {
        count[tolower(str1[i])]++;
    }
    
    // Subtract characters in second string
    for (int i = 0; str2[i] != '\0'; i++) {
        count[tolower(str2[i])]--;
    }
    
    // Check if all counts are zero
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;  // Not anagram
        }
    }
    
    return 1;  // Is anagram
}

int main() {
    char str1[] = "listen";
    char str2[] = "silent";
    
    if (isAnagram(str1, str2)) {
        printf("'%s' and '%s' are anagrams\n", str1, str2);
    } else {
        printf("'%s' and '%s' are not anagrams\n", str1, str2);
    }
    
    return 0;
}
```

**Output:**
```
'listen' and 'silent' are anagrams
```

## String Formatting

### Using sprintf()

```c
#include <stdio.h>

int main() {
    char buffer[100];
    int num = 42;
    char str[] = "Hello";
    
    // Format string
    sprintf(buffer, "Number: %d, String: %s", num, str);
    printf("Formatted: %s\n", buffer);
    
    // Format with precision
    double pi = 3.14159;
    sprintf(buffer, "Pi: %.2f", pi);
    printf("Pi: %s\n", buffer);
    
    return 0;
}
```

**Output:**
```
Formatted: Number: 42, String: Hello
Pi: Pi: 3.14
```

### Using snprintf()

```c
#include <stdio.h>

int main() {
    char buffer[10];
    char longStr[] = "This is a very long string";
    
    // Safe string formatting
    int written = snprintf(buffer, sizeof(buffer), "%s", longStr);
    
    printf("Buffer: '%s'\n", buffer);
    printf("Characters written: %d\n", written);
    printf("Buffer size: %zu\n", sizeof(buffer));
    
    return 0;
}
```

**Output:**
```
Buffer: 'This is a'
Characters written: 26
Buffer size: 10
```

## Common String Patterns

### 1. **String Search and Replace**

```c
#include <stdio.h>
#include <string.h>

void replaceString(char* str, const char* old, const char* new) {
    char* pos = strstr(str, old);
    
    if (pos != NULL) {
        int oldLen = strlen(old);
        int newLen = strlen(new);
        
        if (newLen > oldLen) {
            // Move remaining characters
            memmove(pos + newLen, pos + oldLen, strlen(pos + oldLen) + 1);
        }
        
        // Copy new string
        memcpy(pos, new, newLen);
    }
}

int main() {
    char str[100] = "Hello World";
    
    printf("Original: %s\n", str);
    replaceString(str, "World", "C Programming");
    printf("After replacement: %s\n", str);
    
    return 0;
}
```

### 2. **String Split and Join**

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** splitString(const char* str, char delimiter, int* count) {
    *count = 0;
    char* temp = strdup(str);
    char* token = strtok(temp, &delimiter);
    
    // Count tokens
    while (token != NULL) {
        (*count)++;
        token = strtok(NULL, &delimiter);
    }
    
    // Allocate array
    char** result = malloc(*count * sizeof(char*));
    
    // Reset and split
    free(temp);
    temp = strdup(str);
    token = strtok(temp, &delimiter);
    
    int i = 0;
    while (token != NULL) {
        result[i] = strdup(token);
        i++;
        token = strtok(NULL, &delimiter);
    }
    
    free(temp);
    return result;
}

int main() {
    char str[] = "apple,banana,cherry";
    int count;
    
    char** tokens = splitString(str, ',', &count);
    
    printf("Split into %d tokens:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Token %d: %s\n", i, tokens[i]);
        free(tokens[i]);
    }
    
    free(tokens);
    return 0;
}
```

## Best Practices

### 1. **Always Check Buffer Size**

```c
// Good: Check buffer size
char dest[10];
if (strlen(source) < sizeof(dest)) {
    strcpy(dest, source);
} else {
    strncpy(dest, source, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';
}

// Bad: No size checking
strcpy(dest, source);  // May cause buffer overflow
```

### 2. **Use Safe String Functions**

```c
// Good: Use safe functions
strncpy(dest, source, dest_size - 1);
dest[dest_size - 1] = '\0';

// Bad: Unsafe functions
strcpy(dest, source);  // No bounds checking
```

### 3. **Handle String Literals Carefully**

```c
// Good: Use const for string literals
const char* str = "Hello";

// Bad: Modifying string literal
char* str = "Hello";
str[0] = 'h';  // Undefined behavior
```

## Common Mistakes

### 1. **Buffer Overflow**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[5];
    char source[] = "Hello World";
    
    // Wrong: Buffer overflow
    strcpy(dest, source);
    
    return 0;
}
```

### 2. **Missing Null Terminator**

```c
#include <stdio.h>

int main() {
    char str[5] = {'H', 'e', 'l', 'l', 'o'};  // No '\0'
    
    printf("%s\n", str);  // Undefined behavior
    
    return 0;
}
```

### 3. **String Comparison with ==**

```c
#include <stdio.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    
    // Wrong: Comparing addresses, not content
    if (str1 == str2) {
        printf("Equal\n");
    } else {
        printf("Not equal\n");
    }
    
    // Correct: Use strcmp
    if (strcmp(str1, str2) == 0) {
        printf("Equal\n");
    } else {
        printf("Not equal\n");
    }
    
    return 0;
}
```

## Summary

**Key Points:**
- Strings are null-terminated character arrays
- Always ensure null termination
- Use library functions for common operations
- Check buffer sizes to prevent overflow
- Handle string literals carefully

**Best Practices:**
- Use safe string functions (strncpy, strncat)
- Always check buffer sizes
- Handle memory allocation properly
- Use const for string literals
- Validate input strings

**Common Use Cases:**
- Text processing and manipulation
- Input validation and parsing
- Data formatting and output
- Pattern matching and search
- String analysis and statistics 