# Linked Lists in C Programming

## Overview

A linked list is a linear data structure where elements are stored in nodes, and each node contains data and a reference (pointer) to the next node in the sequence. Unlike arrays, linked lists don't require contiguous memory allocation.

## Types of Linked Lists

### 1. **Singly Linked List**
Each node has data and a pointer to the next node.

### 2. **Doubly Linked List**
Each node has data and pointers to both next and previous nodes.

### 3. **Circular Linked List**
The last node points back to the first node.

## Singly Linked List Implementation

### Basic Structure

```c
#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// List structure to keep track of head
typedef struct {
    Node* head;
    int size;
} LinkedList;
```

### Creating a Node

```c
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

### Insertion Operations

#### 1. **Insert at Beginning**

```c
void insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}
```

#### 2. **Insert at End**

```c
void insertAtEnd(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}
```

#### 3. **Insert at Position**

```c
void insertAtPosition(LinkedList* list, int data, int position) {
    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }
    
    if (position == 0) {
        insertAtBeginning(list, data);
        return;
    }
    
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    Node* current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
}
```

### Deletion Operations

#### 1. **Delete from Beginning**

```c
void deleteFromBeginning(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}
```

#### 2. **Delete from End**

```c
void deleteFromEnd(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
    } else {
        Node* current = list->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->size--;
}
```

#### 3. **Delete at Position**

```c
void deleteAtPosition(LinkedList* list, int position) {
    if (list->head == NULL || position < 0 || position >= list->size) {
        printf("Invalid position or list is empty\n");
        return;
    }
    
    if (position == 0) {
        deleteFromBeginning(list);
        return;
    }
    
    Node* current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;
}
```

### Search Operations

#### 1. **Search by Value**

```c
Node* searchByValue(LinkedList* list, int value) {
    Node* current = list->head;
    
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;  // Not found
}
```

#### 2. **Search by Position**

```c
Node* searchByPosition(LinkedList* list, int position) {
    if (position < 0 || position >= list->size) {
        return NULL;
    }
    
    Node* current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    
    return current;
}
```

### Display and Utility Functions

#### 1. **Display List**

```c
void displayList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
```

#### 2. **Get List Size**

```c
int getSize(LinkedList* list) {
    return list->size;
}
```

#### 3. **Check if Empty**

```c
int isEmpty(LinkedList* list) {
    return list->head == NULL;
}
```

### Complete Implementation

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

// Function declarations
Node* createNode(int data);
void initializeList(LinkedList* list);
void insertAtBeginning(LinkedList* list, int data);
void insertAtEnd(LinkedList* list, int data);
void insertAtPosition(LinkedList* list, int data, int position);
void deleteFromBeginning(LinkedList* list);
void deleteFromEnd(LinkedList* list);
void deleteAtPosition(LinkedList* list, int position);
Node* searchByValue(LinkedList* list, int value);
Node* searchByPosition(LinkedList* list, int position);
void displayList(LinkedList* list);
int getSize(LinkedList* list);
int isEmpty(LinkedList* list);
void freeList(LinkedList* list);

int main() {
    LinkedList list;
    initializeList(&list);
    
    // Insert elements
    insertAtEnd(&list, 10);
    insertAtEnd(&list, 20);
    insertAtEnd(&list, 30);
    insertAtBeginning(&list, 5);
    insertAtPosition(&list, 15, 2);
    
    // Display list
    displayList(&list);
    printf("Size: %d\n", getSize(&list));
    
    // Search operations
    Node* found = searchByValue(&list, 20);
    if (found != NULL) {
        printf("Found 20 in the list\n");
    }
    
    // Delete operations
    deleteFromBeginning(&list);
    deleteFromEnd(&list);
    deleteAtPosition(&list, 1);
    
    displayList(&list);
    
    // Free memory
    freeList(&list);
    
    return 0;
}

// Implementation of all functions...
// (Previous implementations would go here)

void initializeList(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

void freeList(LinkedList* list) {
    Node* current = list->head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->size = 0;
}
```

### Output

```
List: 5 -> 10 -> 15 -> 20 -> 30 -> NULL
Size: 5
Found 20 in the list
List: 10 -> 20 -> NULL
```

## Doubly Linked List

### Structure Definition

```c
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList;
```

### Insertion in Doubly Linked List

```c
void insertAtBeginning(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}

void insertAtEnd(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}
```

## Circular Linked List

### Structure and Operations

```c
typedef struct {
    Node* head;
    int size;
} CircularLinkedList;

void insertInCircularList(CircularLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;  // Points to itself
    } else {
        newNode->next = list->head->next;
        list->head->next = newNode;
    }
    list->size++;
}
```

## Applications of Linked Lists

### 1. **Polynomial Addition**

```c
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    Term* current = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        Term* newTerm = (Term*)malloc(sizeof(Term));
        
        if (poly1->exponent > poly2->exponent) {
            newTerm->coefficient = poly1->coefficient;
            newTerm->exponent = poly1->exponent;
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            newTerm->coefficient = poly2->coefficient;
            newTerm->exponent = poly2->exponent;
            poly2 = poly2->next;
        } else {
            newTerm->coefficient = poly1->coefficient + poly2->coefficient;
            newTerm->exponent = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        newTerm->next = NULL;
        
        if (result == NULL) {
            result = newTerm;
            current = newTerm;
        } else {
            current->next = newTerm;
            current = newTerm;
        }
    }
    
    return result;
}
```

### 2. **LRU Cache Implementation**

```c
typedef struct LRUNode {
    int key;
    int value;
    struct LRUNode* next;
    struct LRUNode* prev;
} LRUNode;

typedef struct {
    LRUNode* head;
    LRUNode* tail;
    int capacity;
    int size;
} LRUCache;

LRUNode* get(LRUCache* cache, int key) {
    // Implementation for LRU cache get operation
    // Move accessed node to front
    return NULL;
}
```

## Performance Analysis

### Time Complexity

| Operation | Singly Linked List | Doubly Linked List |
|-----------|-------------------|-------------------|
| Insert at beginning | O(1) | O(1) |
| Insert at end | O(n) | O(1) |
| Insert at position | O(n) | O(n) |
| Delete from beginning | O(1) | O(1) |
| Delete from end | O(n) | O(1) |
| Search | O(n) | O(n) |
| Access by position | O(n) | O(n) |

### Space Complexity
- **Singly Linked List**: O(n)
- **Doubly Linked List**: O(n)
- **Circular Linked List**: O(n)

## Best Practices

### 1. **Memory Management**

```c
// Always free nodes when deleting
void deleteNode(Node* node) {
    if (node != NULL) {
        free(node);
    }
}

// Free entire list
void freeList(LinkedList* list) {
    Node* current = list->head;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    list->head = NULL;
    list->size = 0;
}
```

### 2. **Error Handling**

```c
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
```

### 3. **Boundary Conditions**

```c
void insertAtPosition(LinkedList* list, int data, int position) {
    // Check for valid position
    if (position < 0 || position > list->size) {
        printf("Invalid position\n");
        return;
    }
    
    // Handle empty list
    if (list->head == NULL && position == 0) {
        insertAtBeginning(list, data);
        return;
    }
    
    // Rest of implementation...
}
```

## Common Mistakes

### 1. **Memory Leaks**

```c
// Wrong: Not freeing memory
void deleteFromBeginning(LinkedList* list) {
    list->head = list->head->next;  // Memory leak!
}

// Correct: Free memory
void deleteFromBeginning(LinkedList* list) {
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);  // Free the node
}
```

### 2. **Null Pointer Dereference**

```c
// Wrong: No null check
void displayList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

// Correct: Check for null
void displayList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}
```

## Summary

**Key Points:**
- Linked lists provide dynamic memory allocation
- Different types serve different purposes
- Proper memory management is crucial
- Time complexity varies by operation type

**Best Practices:**
- Always check for null pointers
- Free memory when deleting nodes
- Handle boundary conditions
- Use appropriate list type for your needs

**Common Use Cases:**
- Dynamic data structures
- Memory-efficient storage
- Insertion/deletion heavy operations
- Implementing stacks and queues
- Polynomial arithmetic
- LRU cache implementation 