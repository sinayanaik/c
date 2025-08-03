# Structure Basics in C Programming

## Overview

Structures in C are user-defined data types that allow you to group related data items of different types under a single name. They provide a way to create complex data types that can represent real-world entities.

## Structure Declaration

### Basic Syntax

```c
struct structure_name {
    data_type member1;
    data_type member2;
    // ... more members
};
```

### Simple Structure Example

```c
#include <stdio.h>

// Define a structure
struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    // Declare a structure variable
    struct Student student1;
    
    // Initialize members
    student1.id = 1001;
    strcpy(student1.name, "John Doe");
    student1.gpa = 3.8;
    
    // Access and print members
    printf("Student ID: %d\n", student1.id);
    printf("Student Name: %s\n", student1.name);
    printf("Student GPA: %.2f\n", student1.gpa);
    
    return 0;
}
```

## Structure Initialization

### 1. **Declaration with Initialization**

```c
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    // Method 1: Initialize in order
    struct Point p1 = {10, 20};
    
    // Method 2: Designated initializers (C99)
    struct Point p2 = {.x = 30, .y = 40};
    
    // Method 3: Initialize some members
    struct Point p3 = {50};  // y will be 0
    
    printf("p1: (%d, %d)\n", p1.x, p1.y);
    printf("p2: (%d, %d)\n", p2.x, p2.y);
    printf("p3: (%d, %d)\n", p3.x, p3.y);
    
    return 0;
}
```

### 2. **Array of Structures**

```c
#include <stdio.h>

struct Book {
    char title[100];
    char author[50];
    int year;
    float price;
};

int main() {
    struct Book library[3] = {
        {"The C Programming Language", "Kernighan & Ritchie", 1978, 29.99},
        {"C Programming: A Modern Approach", "K.N. King", 1996, 45.50},
        {"Expert C Programming", "Peter van der Linden", 1994, 39.99}
    };
    
    for (int i = 0; i < 3; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Title: %s\n", library[i].title);
        printf("  Author: %s\n", library[i].author);
        printf("  Year: %d\n", library[i].year);
        printf("  Price: $%.2f\n\n", library[i].price);
    }
    
    return 0;
}
```

## Structure Members

### Different Data Types

```c
#include <stdio.h>

struct Employee {
    int id;                    // Integer
    char name[50];             // Character array
    float salary;              // Float
    double bonus;              // Double
    char* department;          // Pointer
    struct {
        int day;
        int month;
        int year;
    } hire_date;              // Nested structure
};

int main() {
    struct Employee emp = {
        .id = 1001,
        .name = "Alice Johnson",
        .salary = 75000.0,
        .bonus = 5000.0,
        .department = "Engineering",
        .hire_date = {15, 3, 2020}
    };
    
    printf("Employee Details:\n");
    printf("ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Salary: $%.2f\n", emp.salary);
    printf("Bonus: $%.2f\n", emp.bonus);
    printf("Department: %s\n", emp.department);
    printf("Hire Date: %d/%d/%d\n", 
           emp.hire_date.day, emp.hire_date.month, emp.hire_date.year);
    
    return 0;
}
```

## Structure Operations

### 1. **Copying Structures**

```c
#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    struct Person person1 = {"John", 25, 175.5};
    struct Person person2;
    
    // Copy structure
    person2 = person1;
    
    // Modify copy
    strcpy(person2.name, "Jane");
    person2.age = 30;
    
    printf("Person 1: %s, %d years, %.1f cm\n", 
           person1.name, person1.age, person1.height);
    printf("Person 2: %s, %d years, %.1f cm\n", 
           person2.name, person2.age, person2.height);
    
    return 0;
}
```

### 2. **Comparing Structures**

```c
#include <stdio.h>
#include <string.h>

struct Rectangle {
    int width;
    int height;
};

int compareRectangles(struct Rectangle r1, struct Rectangle r2) {
    if (r1.width == r2.width && r1.height == r2.height) {
        return 0;  // Equal
    } else if (r1.width * r1.height > r2.width * r2.height) {
        return 1;  // r1 is larger
    } else {
        return -1; // r2 is larger
    }
}

int main() {
    struct Rectangle rect1 = {5, 10};
    struct Rectangle rect2 = {10, 5};
    
    int result = compareRectangles(rect1, rect2);
    
    if (result == 0) {
        printf("Rectangles are equal\n");
    } else if (result > 0) {
        printf("Rectangle 1 is larger\n");
    } else {
        printf("Rectangle 2 is larger\n");
    }
    
    return 0;
}
```

## Nested Structures

### Structure within Structure

```c
#include <stdio.h>

struct Address {
    char street[100];
    char city[50];
    char state[30];
    int zip_code;
};

struct Contact {
    char name[50];
    char phone[20];
    char email[100];
    struct Address address;
};

int main() {
    struct Contact contact = {
        .name = "Bob Smith",
        .phone = "555-1234",
        .email = "bob@example.com",
        .address = {
            .street = "123 Main St",
            .city = "Anytown",
            .state = "CA",
            .zip_code = 12345
        }
    };
    
    printf("Contact Information:\n");
    printf("Name: %s\n", contact.name);
    printf("Phone: %s\n", contact.phone);
    printf("Email: %s\n", contact.email);
    printf("Address: %s, %s, %s %d\n",
           contact.address.street,
           contact.address.city,
           contact.address.state,
           contact.address.zip_code);
    
    return 0;
}
```

## Self-Referential Structures

### Linked List Node

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Create nodes
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));
    struct Node* third = malloc(sizeof(struct Node));
    
    // Initialize nodes
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = NULL;
    
    // Traverse and print
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    
    // Free memory
    free(third);
    free(second);
    free(head);
    
    return 0;
}
```

## Structure Pointers

### Pointer to Structure

```c
#include <stdio.h>

struct Circle {
    int x, y;
    float radius;
};

int main() {
    struct Circle circle = {10, 20, 5.5};
    struct Circle* ptr = &circle;
    
    // Access using pointer
    printf("Circle center: (%d, %d)\n", ptr->x, ptr->y);
    printf("Circle radius: %.1f\n", ptr->radius);
    
    // Modify using pointer
    ptr->x = 15;
    ptr->y = 25;
    ptr->radius = 6.0;
    
    printf("Modified circle center: (%d, %d)\n", circle.x, circle.y);
    printf("Modified circle radius: %.1f\n", circle.radius);
    
    return 0;
}
```

### Dynamic Structure Allocation

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

int main() {
    // Allocate structure dynamically
    struct Product* product = malloc(sizeof(struct Product));
    
    if (product == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Initialize structure
    strcpy(product->name, "Laptop");
    product->price = 999.99;
    product->quantity = 10;
    
    printf("Product: %s\n", product->name);
    printf("Price: $%.2f\n", product->price);
    printf("Quantity: %d\n", product->quantity);
    
    // Free memory
    free(product);
    
    return 0;
}
```

## Structure as Function Parameters

### Passing by Value

```c
#include <stdio.h>

struct Rectangle {
    int width;
    int height;
};

int calculateArea(struct Rectangle rect) {
    return rect.width * rect.height;
}

void printRectangle(struct Rectangle rect) {
    printf("Rectangle: %d x %d\n", rect.width, rect.height);
    printf("Area: %d\n", calculateArea(rect));
}

int main() {
    struct Rectangle rect = {5, 10};
    printRectangle(rect);
    
    return 0;
}
```

### Passing by Reference

```c
#include <stdio.h>

struct Student {
    char name[50];
    int scores[5];
    float average;
};

void calculateAverage(struct Student* student) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->scores[i];
    }
    student->average = (float)sum / 5;
}

void printStudent(struct Student* student) {
    printf("Name: %s\n", student->name);
    printf("Scores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student->scores[i]);
    }
    printf("\nAverage: %.2f\n", student->average);
}

int main() {
    struct Student student = {
        .name = "Alice",
        .scores = {85, 90, 78, 92, 88}
    };
    
    calculateAverage(&student);
    printStudent(&student);
    
    return 0;
}
```

## Typedef with Structures

### Creating Type Aliases

```c
#include <stdio.h>

// Define structure with typedef
typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

// Function using the new type
void printTime(Time t) {
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

Time addTime(Time t1, Time t2) {
    Time result;
    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes + result.seconds / 60;
    result.hours = t1.hours + t2.hours + result.minutes / 60;
    
    result.seconds %= 60;
    result.minutes %= 60;
    result.hours %= 24;
    
    return result;
}

int main() {
    Time time1 = {2, 30, 45};
    Time time2 = {1, 15, 20};
    
    printf("Time 1: ");
    printTime(time1);
    
    printf("Time 2: ");
    printTime(time2);
    
    Time sum = addTime(time1, time2);
    printf("Sum: ");
    printTime(sum);
    
    return 0;
}
```

## Structure Arrays and Sorting

### Array of Structures

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void printEmployee(Employee emp) {
    printf("Name: %s, Age: %d, Salary: $%.2f\n", 
           emp.name, emp.age, emp.salary);
}

void sortByAge(Employee arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].age > arr[j + 1].age) {
                Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    Employee employees[] = {
        {"Alice", 25, 50000.0},
        {"Bob", 30, 60000.0},
        {"Charlie", 22, 45000.0},
        {"Diana", 35, 70000.0}
    };
    
    int size = sizeof(employees) / sizeof(employees[0]);
    
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printEmployee(employees[i]);
    }
    
    sortByAge(employees, size);
    
    printf("\nAfter sorting by age:\n");
    for (int i = 0; i < size; i++) {
        printEmployee(employees[i]);
    }
    
    return 0;
}
```

## Best Practices

### 1. **Use Meaningful Member Names**

```c
// Good: Clear member names
struct Student {
    int student_id;
    char full_name[100];
    float grade_point_average;
};

// Bad: Unclear names
struct Student {
    int id;
    char name[100];
    float gpa;
};
```

### 2. **Initialize Structures Properly**

```c
// Good: Initialize all members
struct Point p = {0, 0};

// Bad: Uninitialized structure
struct Point p;  // Contains garbage values
```

### 3. **Use const for Read-Only Parameters**

```c
// Good: Use const for read-only access
void printStudent(const struct Student* student) {
    printf("Name: %s\n", student->name);
}

// Bad: No const protection
void printStudent(struct Student* student) {
    // Could accidentally modify student
}
```

## Common Mistakes

### 1. **Forgetting Structure Tag**

```c
// Wrong: Missing structure tag
struct {
    int x, y;
} point;

// Correct: Include structure tag
struct Point {
    int x, y;
} point;
```

### 2. **Comparing Structures Directly**

```c
#include <stdio.h>

struct Rectangle {
    int width, height;
};

int main() {
    struct Rectangle r1 = {5, 10};
    struct Rectangle r2 = {5, 10};
    
    // Wrong: Direct comparison
    // if (r1 == r2) { ... }
    
    // Correct: Compare members
    if (r1.width == r2.width && r1.height == r2.height) {
        printf("Rectangles are equal\n");
    }
    
    return 0;
}
```

### 3. **Memory Leaks with Dynamic Structures**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;
    
    // Use the structure
    printf("Data: %d\n", head->data);
    
    // Don't forget to free
    free(head);  // Important!
    
    return 0;
}
```

## Summary

**Key Points:**
- Structures group related data of different types
- Use dot operator (.) for direct access
- Use arrow operator (->) for pointer access
- Structures can be nested and self-referential
- Use typedef for cleaner code

**Best Practices:**
- Use meaningful member names
- Initialize structures properly
- Use const for read-only access
- Handle memory allocation carefully
- Compare structures member by member

**Common Use Cases:**
- Representing real-world entities
- Creating complex data types
- Building data structures
- Organizing related data
- Function parameter grouping 