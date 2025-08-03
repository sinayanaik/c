/*
 * Exercise: Linked List Implementation
 * 
 * Implement a complete linked list data structure with the following operations:
 * 
 * 1. Create a new node
 * 2. Insert at beginning
 * 3. Insert at end
 * 4. Insert at specific position
 * 5. Delete from beginning
 * 6. Delete from end
 * 7. Delete from specific position
 * 8. Search for an element
 * 9. Display the list
 * 10. Count nodes
 * 11. Reverse the list
 * 12. Check if list is empty
 * 13. Free the entire list
 * 
 * Requirements:
 * - Use proper memory management (malloc/free)
 * - Handle edge cases (empty list, single node, invalid positions)
 * - Implement error checking
 * - Use clear function names and documentation
 * 
 * Example Usage:
 * List: 10 -> 20 -> 30 -> 40 -> NULL
 * Length: 4
 * Search for 30: Found at position 2
 * After reversing: 40 -> 30 -> 20 -> 10 -> NULL
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// List structure (optional - for better organization)
typedef struct {
    Node *head;
    int size;
} LinkedList;

// Function prototypes
Node* createNode(int data);
LinkedList* createList();
void insertAtBeginning(LinkedList *list, int data);
void insertAtEnd(LinkedList *list, int data);
void insertAtPosition(LinkedList *list, int data, int position);
int deleteFromBeginning(LinkedList *list);
int deleteFromEnd(LinkedList *list);
int deleteFromPosition(LinkedList *list, int position);
int searchElement(LinkedList *list, int data);
void displayList(LinkedList *list);
int getLength(LinkedList *list);
void reverseList(LinkedList *list);
int isEmpty(LinkedList *list);
void freeList(LinkedList *list);

int main() {
    // TODO: Implement your solution here
    
    return 0;
}

// TODO: Implement all the functions above

/*
 * Hints:
 * 1. Always check for null pointers before dereferencing
 * 2. Use temporary pointers when traversing the list
 * 3. For insertion/deletion, handle the head pointer separately
 * 4. For reverse, use three pointers (prev, current, next)
 * 5. Remember to update the size field if using LinkedList structure
 * 
 * Important Notes:
 * - Always free memory when deleting nodes
 * - Check for memory allocation failures
 * - Handle edge cases properly
 * - Consider using a tail pointer for O(1) insertions at end
 * 
 * Extension Challenges:
 * 1. Implement circular linked list
 * 2. Add support for doubly linked list
 * 3. Implement merge sort for linked list
 * 4. Add support for generic data types (void pointers)
 * 5. Implement list concatenation and splitting
 * 6. Add support for detecting cycles in the list
 */ 