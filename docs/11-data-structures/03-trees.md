# Trees in C Programming

## Overview

A tree is a hierarchical data structure that consists of nodes connected by edges. Each node contains data and references to its child nodes. Trees are fundamental data structures used in many applications including file systems, databases, and compiler design.

## Types of Trees

### 1. **Binary Tree**
Each node has at most two children (left and right).

### 2. **Binary Search Tree (BST)**
A binary tree where for each node, all left descendants have values less than the node, and all right descendants have values greater than the node.

### 3. **AVL Tree**
A self-balancing binary search tree where the heights of the left and right subtrees differ by at most one.

### 4. **Red-Black Tree**
A self-balancing binary search tree with additional properties for maintaining balance.

## Binary Tree Implementation

### Basic Structure

```c
#include <stdio.h>
#include <stdlib.h>

// Node structure for binary tree
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Tree structure
typedef struct {
    TreeNode* root;
    int size;
} BinaryTree;
```

### Creating a Node

```c
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
```

### Basic Operations

#### 1. **Insert Node**

```c
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}
```

#### 2. **Search Node**

```c
TreeNode* searchNode(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    
    return searchNode(root->right, data);
}
```

#### 3. **Find Minimum Value**

```c
TreeNode* findMin(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    while (root->left != NULL) {
        root = root->left;
    }
    
    return root;
}
```

#### 4. **Find Maximum Value**

```c
TreeNode* findMax(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    while (root->right != NULL) {
        root = root->right;
    }
    
    return root;
}
```

#### 5. **Delete Node**

```c
TreeNode* deleteNode(TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the inorder successor (smallest in right subtree)
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}
```

## Tree Traversal

### 1. **Inorder Traversal (Left-Root-Right)**

```c
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
```

### 2. **Preorder Traversal (Root-Left-Right)**

```c
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
```

### 3. **Postorder Traversal (Left-Right-Root)**

```c
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
```

### 4. **Level Order Traversal (Breadth-First)**

```c
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    TreeNode* data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, TreeNode* node) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = node;
}

TreeNode* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return NULL;
    }
    
    TreeNode* node = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    
    return node;
}

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, root);
    
    while (!isEmpty(&queue)) {
        TreeNode* current = dequeue(&queue);
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queue, current->right);
        }
    }
    printf("\n");
}
```

## Tree Properties

### 1. **Height of Tree**

```c
int getHeight(TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}
```

### 2. **Size of Tree (Number of Nodes)**

```c
int getSize(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    return 1 + getSize(root->left) + getSize(root->right);
}
```

### 3. **Check if Tree is Balanced**

```c
bool isBalanced(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    return abs(leftHeight - rightHeight) <= 1 && 
           isBalanced(root->left) && 
           isBalanced(root->right);
}
```

## Complete Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int getHeight(TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    TreeNode* root = NULL;
    
    // Insert nodes
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    printf("Height of tree: %d\n", getHeight(root));
    
    freeTree(root);
    return 0;
}
```

## Applications of Trees

1. **File Systems**: Directory structures
2. **Database Indexing**: B-trees for efficient searching
3. **Expression Trees**: Representing mathematical expressions
4. **Decision Trees**: Machine learning and AI
5. **Syntax Trees**: Compiler design
6. **Game Trees**: Game AI and decision making

## Time Complexity

- **Search**: O(h) where h is height of tree
- **Insert**: O(h)
- **Delete**: O(h)
- **Traversal**: O(n) where n is number of nodes

For a balanced tree, h = log(n), making operations O(log n). 