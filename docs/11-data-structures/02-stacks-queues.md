# Stacks and Queues in C Programming

## Overview

Stacks and Queues are fundamental linear data structures that follow specific ordering principles. They are essential for many algorithms and are often used as building blocks for more complex data structures.

## Stack Data Structure

### Definition
A Stack is a Last-In-First-Out (LIFO) data structure where elements are added and removed from the same end (top).

### Basic Operations
- **Push**: Add element to the top
- **Pop**: Remove element from the top
- **Peek/Top**: View the top element without removing
- **isEmpty**: Check if stack is empty
- **isFull**: Check if stack is full (for fixed-size stacks)

### Array-Based Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push element to stack
bool push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return false;
    }
    
    stack->data[++stack->top] = value;
    return true;
}

// Pop element from stack
bool pop(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return false;
    }
    
    *value = stack->data[stack->top--];
    return true;
}

// Peek at top element
bool peek(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return false;
    }
    
    *value = stack->data[stack->top];
    return true;
}

// Display stack
void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}
```

### Linked List-Based Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

// Create new node
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

// Initialize stack
void initializeStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// Check if stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Push element to stack
bool push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        return false;
    }
    
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    return true;
}

// Pop element from stack
bool pop(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return false;
    }
    
    Node* temp = stack->top;
    *value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return true;
}

// Peek at top element
bool peek(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return false;
    }
    
    *value = stack->top->data;
    return true;
}

// Free stack memory
void freeStack(Stack* stack) {
    Node* current = stack->top;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    stack->top = NULL;
    stack->size = 0;
}
```

## Queue Data Structure

### Definition
A Queue is a First-In-First-Out (FIFO) data structure where elements are added at the rear and removed from the front.

### Basic Operations
- **Enqueue**: Add element to the rear
- **Dequeue**: Remove element from the front
- **Front**: View the front element without removing
- **isEmpty**: Check if queue is empty
- **isFull**: Check if queue is full (for fixed-size queues)

### Array-Based Implementation (Circular Queue)

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Initialize queue
void initializeQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// Check if queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Check if queue is full
bool isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

// Enqueue element
bool enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return false;
    }
    
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
    queue->size++;
    return true;
}

// Dequeue element
bool dequeue(Queue* queue, int* value) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return false;
    }
    
    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return true;
}

// Get front element
bool front(Queue* queue, int* value) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return false;
    }
    
    *value = queue->data[queue->front];
    return true;
}

// Display queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue (front to rear): ");
    int count = 0;
    int index = queue->front;
    
    while (count < queue->size) {
        printf("%d ", queue->data[index]);
        index = (index + 1) % MAX_SIZE;
        count++;
    }
    printf("\n");
}
```

### Linked List-Based Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Create new node
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

// Initialize queue
void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// Check if queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Enqueue element
bool enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        return false;
    }
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    
    queue->size++;
    return true;
}

// Dequeue element
bool dequeue(Queue* queue, int* value) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return false;
    }
    
    Node* temp = queue->front;
    *value = temp->data;
    queue->front = temp->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    queue->size--;
    return true;
}

// Get front element
bool front(Queue* queue, int* value) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return false;
    }
    
    *value = queue->front->data;
    return true;
}

// Free queue memory
void freeQueue(Queue* queue) {
    Node* current = queue->front;
    Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}
```

## Priority Queue

### Definition
A Priority Queue is a queue where each element has a priority, and elements are dequeued based on their priority.

### Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    int priority;
} PriorityItem;

typedef struct {
    PriorityItem* items;
    int capacity;
    int size;
} PriorityQueue;

// Initialize priority queue
void initializePriorityQueue(PriorityQueue* pq, int capacity) {
    pq->items = (PriorityItem*)malloc(capacity * sizeof(PriorityItem));
    pq->capacity = capacity;
    pq->size = 0;
}

// Check if priority queue is empty
bool isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

// Check if priority queue is full
bool isFull(PriorityQueue* pq) {
    return pq->size == pq->capacity;
}

// Enqueue with priority (higher number = higher priority)
bool enqueue(PriorityQueue* pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Priority queue overflow\n");
        return false;
    }
    
    int i = pq->size - 1;
    
    // Find position to insert based on priority
    while (i >= 0 && pq->items[i].priority < priority) {
        pq->items[i + 1] = pq->items[i];
        i--;
    }
    
    pq->items[i + 1].data = data;
    pq->items[i + 1].priority = priority;
    pq->size++;
    
    return true;
}

// Dequeue highest priority element
bool dequeue(PriorityQueue* pq, int* data, int* priority) {
    if (isEmpty(pq)) {
        printf("Priority queue underflow\n");
        return false;
    }
    
    *data = pq->items[0].data;
    *priority = pq->items[0].priority;
    
    // Shift elements
    for (int i = 0; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
    }
    
    pq->size--;
    return true;
}

// Free priority queue memory
void freePriorityQueue(PriorityQueue* pq) {
    free(pq->items);
    pq->items = NULL;
    pq->capacity = 0;
    pq->size = 0;
}
```

## Applications

### 1. **Stack Applications**

#### Expression Evaluation

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int evaluateExpression(char* expression) {
    Stack values, operators;
    initializeStack(&values);
    initializeStack(&operators);
    
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == ' ') continue;
        
        if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            push(&values, num);
        } else if (expression[i] == '(') {
            push(&operators, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(&operators) && peek(&operators) != '(') {
                char op;
                pop(&operators, &op);
                int b, a;
                pop(&values, &b);
                pop(&values, &a);
                push(&values, applyOperator(a, b, op));
            }
            if (!isEmpty(&operators)) {
                char temp;
                pop(&operators, &temp); // Remove '('
            }
        } else if (isOperator(expression[i])) {
            while (!isEmpty(&operators) && 
                   getPrecedence(peek(&operators)) >= getPrecedence(expression[i])) {
                char op;
                pop(&operators, &op);
                int b, a;
                pop(&values, &b);
                pop(&values, &a);
                push(&values, applyOperator(a, b, op));
            }
            push(&operators, expression[i]);
        }
    }
    
    while (!isEmpty(&operators)) {
        char op;
        pop(&operators, &op);
        int b, a;
        pop(&values, &b);
        pop(&values, &a);
        push(&values, applyOperator(a, b, op));
    }
    
    int result;
    pop(&values, &result);
    return result;
}
```

### Output

```
Expression: 10 + 2 * (6 - 3)
Result: 16
Expression: 100 * 2 + 12
Result: 212
Expression: 100 * ( 2 + 12 )
Result: 1400
```

#### Balanced Parentheses

```c
bool isBalanced(char* expression) {
    Stack stack;
    initializeStack(&stack);
    
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (isEmpty(&stack)) {
                return false;
            }
            
            char top;
            pop(&stack, &top);
            
            if ((expression[i] == ')' && top != '(') ||
                (expression[i] == '}' && top != '{') ||
                (expression[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    return isEmpty(&stack);
}
```

### Output

```
Expression: {[()]} -> Balanced
Expression: {[(])} -> Not Balanced
Expression: {{[[(())]]}} -> Balanced
```

### 2. **Queue Applications**

#### Breadth-First Search (BFS)

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void BFS(Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    Queue queue;
    initializeQueue(&queue);
    
    visited[startVertex] = true;
    enqueue(&queue, startVertex);
    
    printf("BFS traversal: ");
    
    while (!isEmpty(&queue)) {
        int vertex;
        dequeue(&queue, &vertex);
        printf("%d ", vertex);
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[vertex][i] && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
    printf("\n");
}
```

### Output

```
BFS traversal: 2 0 3 1 
```

#### Print Binary Tree Level by Level

```c
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;
    
    Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, (int)root);
    
    while (!isEmpty(&queue)) {
        int nodeValue;
        dequeue(&queue, &nodeValue);
        TreeNode* node = (TreeNode*)nodeValue;
        
        printf("%d ", node->data);
        
        if (node->left) {
            enqueue(&queue, (int)node->left);
        }
        if (node->right) {
            enqueue(&queue, (int)node->right);
        }
    }
    printf("\n");
}
```

### Output

```
Level Order traversal of binary tree is 
1 2 3 4 5 
```

## Performance Analysis

### Time Complexity

| Operation | Array-Based | Linked List-Based |
|-----------|-------------|-------------------|
| Push/Enqueue | O(1) | O(1) |
| Pop/Dequeue | O(1) | O(1) |
| Peek/Front | O(1) | O(1) |
| Search | O(n) | O(n) |

### Space Complexity
- **Array-Based**: O(n) - fixed size
- **Linked List-Based**: O(n) - dynamic size

## Best Practices

### 1. **Memory Management**

```c
// Always free memory for linked list implementations
void cleanupStack(Stack* stack) {
    while (!isEmpty(stack)) {
        int temp;
        pop(stack, &temp);
    }
}

void cleanupQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        int temp;
        dequeue(queue, &temp);
    }
}
```

### 2. **Error Handling**

```c
bool push(Stack* stack, int value) {
    if (stack == NULL) {
        printf("Invalid stack pointer\n");
        return false;
    }
    
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return false;
    }
    
    // Implementation...
    return true;
}
```

### 3. **Boundary Conditions**

```c
bool pop(Stack* stack, int* value) {
    if (stack == NULL || value == NULL) {
        printf("Invalid parameters\n");
        return false;
    }
    
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return false;
    }
    
    // Implementation...
    return true;
}
```

## Common Mistakes

### 1. **Not Checking for Empty Stack/Queue**

```c
// Wrong: No empty check
int pop(Stack* stack) {
    return stack->data[stack->top--];  // May access invalid index
}

// Correct: Check for empty
bool pop(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return false;
    }
    
    *value = stack->data[stack->top--];
    return true;
}
```

### 2. **Memory Leaks in Linked List Implementation**

```c
// Wrong: Not freeing memory
void dequeue(Queue* queue) {
    queue->front = queue->front->next;  // Memory leak!
}

// Correct: Free memory
bool dequeue(Queue* queue, int* value) {
    if (isEmpty(queue)) return false;
    
    Node* temp = queue->front;
    *value = temp->data;
    queue->front = temp->next;
    free(temp);  // Free the node
    
    return true;
}
```

## Summary

**Key Points:**
- Stacks follow LIFO principle
- Queues follow FIFO principle
- Both can be implemented using arrays or linked lists
- Priority queues add priority-based ordering

**Best Practices:**
- Always check for empty/full conditions
- Handle memory properly in linked list implementations
- Use appropriate data structure for your needs
- Consider space and time complexity trade-offs

**Common Use Cases:**
- Function call stack
- Expression evaluation
- Balanced parentheses checking
- Breadth-first search
- Print level order traversal
- Task scheduling with priorities 