# File Handling in C Programming

## Overview

File handling in C allows you to read from and write to files on disk. It provides a way to store data permanently and access it later. C provides a set of functions in the `<stdio.h>` library for file operations.

## File Operations

### Opening Files

```c
#include <stdio.h>

int main() {
    FILE* file;
    
    // Open file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }
    
    // Open file for writing
    FILE* writeFile = fopen("output.txt", "w");
    if (writeFile == NULL) {
        printf("Error opening file for writing\n");
        fclose(file);
        return 1;
    }
    
    // Close files
    fclose(file);
    fclose(writeFile);
    
    return 0;
}
```

### File Modes

| Mode | Description |
|------|-------------|
| `"r"` | Read mode (file must exist) |
| `"w"` | Write mode (creates new file, truncates existing) |
| `"a"` | Append mode (creates new file, appends to existing) |
| `"r+"` | Read and write mode |
| `"w+"` | Read and write mode (truncates existing file) |
| `"a+"` | Read and append mode |
| `"rb"` | Binary read mode |
| `"wb"` | Binary write mode |

## Reading from Files

### 1. **Character by Character Reading**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    char ch;
    printf("File contents:\n");
    
    // Read character by character
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    
    fclose(file);
    return 0;
}
```

### 2. **Line by Line Reading**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    char line[256];
    int lineNumber = 1;
    
    // Read line by line
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("Line %d: %s", lineNumber, line);
        lineNumber++;
    }
    
    fclose(file);
    return 0;
}
```

### 3. **Formatted Reading**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    int number;
    char name[50];
    float score;
    
    // Read formatted data
    while (fscanf(file, "%d %s %f", &number, name, &score) == 3) {
        printf("ID: %d, Name: %s, Score: %.2f\n", number, name, score);
    }
    
    fclose(file);
    return 0;
}
```

## Writing to Files

### 1. **Character by Character Writing**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    char str[] = "Hello, File Handling!";
    
    // Write character by character
    for (int i = 0; str[i] != '\0'; i++) {
        fputc(str[i], file);
    }
    
    fclose(file);
    printf("File written successfully\n");
    return 0;
}
```

### 2. **Line by Line Writing**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    char* lines[] = {
        "First line\n",
        "Second line\n",
        "Third line\n"
    };
    
    // Write line by line
    for (int i = 0; i < 3; i++) {
        fputs(lines[i], file);
    }
    
    fclose(file);
    printf("File written successfully\n");
    return 0;
}
```

### 3. **Formatted Writing**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Write formatted data
    fprintf(file, "ID\tName\t\tScore\n");
    fprintf(file, "1\tAlice\t\t85.5\n");
    fprintf(file, "2\tBob\t\t92.0\n");
    fprintf(file, "3\tCharlie\t\t78.5\n");
    
    fclose(file);
    printf("Student data written to file\n");
    return 0;
}
```

## File Positioning

### File Position Functions

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("test.txt", "w+");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Write some data
    fprintf(file, "Hello World");
    
    // Get current position
    long position = ftell(file);
    printf("Current position: %ld\n", position);
    
    // Move to beginning
    rewind(file);
    printf("After rewind: %ld\n", ftell(file));
    
    // Move to specific position
    fseek(file, 6, SEEK_SET);  // Move to position 6
    printf("After fseek: %ld\n", ftell(file));
    
    // Read from current position
    char ch = fgetc(file);
    printf("Character at position 6: %c\n", ch);
    
    fclose(file);
    return 0;
}
```

### Seeking in Files

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("data.txt", "w+");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Write data
    fprintf(file, "ABCDEFGHIJKLMNOP");
    
    // Seek from beginning
    fseek(file, 5, SEEK_SET);
    printf("Character at position 5: %c\n", fgetc(file));
    
    // Seek from current position
    fseek(file, 3, SEEK_CUR);
    printf("Character 3 positions ahead: %c\n", fgetc(file));
    
    // Seek from end
    fseek(file, -3, SEEK_END);
    printf("Character 3 from end: %c\n", fgetc(file));
    
    fclose(file);
    return 0;
}
```

## Binary File Operations

### Reading/Writing Binary Data

```c
#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    FILE* file = fopen("students.bin", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    struct Student students[] = {
        {1001, "Alice", 3.8},
        {1002, "Bob", 3.5},
        {1003, "Charlie", 3.9}
    };
    
    // Write binary data
    fwrite(students, sizeof(struct Student), 3, file);
    fclose(file);
    
    // Read binary data
    file = fopen("students.bin", "rb");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }
    
    struct Student readStudents[3];
    fread(readStudents, sizeof(struct Student), 3, file);
    
    // Print read data
    for (int i = 0; i < 3; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n",
               readStudents[i].id,
               readStudents[i].name,
               readStudents[i].gpa);
    }
    
    fclose(file);
    return 0;
}
```

## Error Handling

### Comprehensive Error Handling

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE* file = fopen("nonexistent.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }
    
    // Check for read errors
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        if (feof(file)) {
            printf("End of file reached\n");
        } else if (ferror(file)) {
            printf("Error reading file: %s\n", strerror(errno));
        }
    }
    
    fclose(file);
    return 0;
}
```

### File Status Functions

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Check file status
    printf("File opened successfully\n");
    printf("EOF indicator: %s\n", feof(file) ? "Yes" : "No");
    printf("Error indicator: %s\n", ferror(file) ? "Yes" : "No");
    
    // Clear error indicators
    clearerr(file);
    
    fclose(file);
    return 0;
}
```

## Common File Operations

### 1. **Copying Files**

```c
#include <stdio.h>

int copyFile(const char* source, const char* destination) {
    FILE* src = fopen(source, "r");
    if (src == NULL) {
        printf("Error opening source file\n");
        return 1;
    }
    
    FILE* dest = fopen(destination, "w");
    if (dest == NULL) {
        printf("Error opening destination file\n");
        fclose(src);
        return 1;
    }
    
    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
    
    fclose(src);
    fclose(dest);
    
    printf("File copied successfully\n");
    return 0;
}

int main() {
    copyFile("source.txt", "destination.txt");
    return 0;
}
```

### 2. **Counting Lines, Words, Characters**

```c
#include <stdio.h>
#include <ctype.h>

void countFileStats(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    int lines = 0, words = 0, chars = 0;
    char ch, prev = ' ';
    
    while ((ch = fgetc(file)) != EOF) {
        chars++;
        
        if (ch == '\n') {
            lines++;
        }
        
        if (isspace(ch) && !isspace(prev)) {
            words++;
        }
        
        prev = ch;
    }
    
    // Count last word if file doesn't end with space
    if (!isspace(prev)) {
        words++;
    }
    
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    
    fclose(file);
}

int main() {
    countFileStats("input.txt");
    return 0;
}
```

### 3. **Searching in Files**

```c
#include <stdio.h>
#include <string.h>

void searchInFile(const char* filename, const char* searchTerm) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    
    char line[256];
    int lineNumber = 1;
    int found = 0;
    
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, searchTerm) != NULL) {
            printf("Line %d: %s", lineNumber, line);
            found = 1;
        }
        lineNumber++;
    }
    
    if (!found) {
        printf("Search term '%s' not found\n", searchTerm);
    }
    
    fclose(file);
}

int main() {
    searchInFile("data.txt", "hello");
    return 0;
}
```

## Temporary Files

### Creating Temporary Files

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create temporary file
    FILE* temp = tmpfile();
    if (temp == NULL) {
        printf("Error creating temporary file\n");
        return 1;
    }
    
    // Write to temporary file
    fprintf(temp, "This is temporary data\n");
    fprintf(temp, "It will be deleted when program ends\n");
    
    // Read from temporary file
    rewind(temp);
    char line[100];
    while (fgets(line, sizeof(line), temp) != NULL) {
        printf("From temp file: %s", line);
    }
    
    fclose(temp);  // File is automatically deleted
    return 0;
}
```

## Best Practices

### 1. **Always Check File Operations**

```c
// Good: Check file operations
FILE* file = fopen("data.txt", "r");
if (file == NULL) {
    printf("Error opening file\n");
    return 1;
}

// Bad: No error checking
FILE* file = fopen("data.txt", "r");
// May crash if file doesn't exist
```

### 2. **Close Files Properly**

```c
// Good: Always close files
FILE* file = fopen("data.txt", "r");
if (file != NULL) {
    // Use file
    fclose(file);
}

// Bad: Forget to close
FILE* file = fopen("data.txt", "r");
// File remains open - memory leak
```

### 3. **Use Appropriate File Modes**

```c
// Good: Use appropriate mode
FILE* file = fopen("data.txt", "r");  // Read only
FILE* file = fopen("output.txt", "w");  // Write only

// Bad: Use wrong mode
FILE* file = fopen("data.txt", "w");  // Truncates existing file
```

## Common Mistakes

### 1. **Not Checking File Open**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("nonexistent.txt", "r");
    
    // Wrong: No error checking
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);  // May crash
    
    return 0;
}
```

### 2. **Buffer Overflow**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("data.txt", "r");
    if (file == NULL) return 1;
    
    char buffer[10];
    
    // Wrong: May cause buffer overflow
    fgets(buffer, 100, file);  // Buffer size is 10, reading 100
    
    fclose(file);
    return 0;
}
```

### 3. **Forgetting to Close Files**

```c
#include <stdio.h>

int main() {
    FILE* file = fopen("data.txt", "w");
    if (file == NULL) return 1;
    
    fprintf(file, "Hello World");
    
    // Wrong: Forgot to close file
    // fclose(file);
    
    return 0;  // File remains open
}
```

## Summary

**Key Points:**
- Always check if file operations succeed
- Close files when done with them
- Use appropriate file modes
- Handle errors properly
- Use binary mode for non-text files

**Best Practices:**
- Check return values of file functions
- Always close files
- Use appropriate buffer sizes
- Handle errors gracefully
- Use temporary files when needed

**Common Use Cases:**
- Reading configuration files
- Writing log files
- Data persistence
- File processing
- Binary data storage 