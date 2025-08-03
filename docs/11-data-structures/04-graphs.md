# Graphs in C Programming

## Overview

A graph is a non-linear data structure consisting of a finite set of vertices (nodes) and edges that connect these vertices. Graphs are used to represent relationships between objects and are fundamental in computer science for modeling networks, social connections, maps, and more.

## Types of Graphs

### 1. **Undirected Graph**
Edges have no direction - if there's an edge between A and B, you can go from A to B and B to A.

### 2. **Directed Graph (Digraph)**
Edges have direction - if there's an edge from A to B, you can only go from A to B.

### 3. **Weighted Graph**
Edges have weights/costs associated with them.

### 4. **Unweighted Graph**
Edges have no weights.

## Graph Representations

### 1. **Adjacency Matrix**
A 2D array where `matrix[i][j]` represents an edge from vertex i to vertex j.

### 2. **Adjacency List**
An array of linked lists where each list contains vertices adjacent to the vertex.

## Adjacency Matrix Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices;
    int** matrix;
    bool directed;
} Graph;

// Create graph with adjacency matrix
Graph* createGraph(int vertices, bool directed) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    graph->vertices = vertices;
    graph->directed = directed;
    
    // Allocate memory for adjacency matrix
    graph->matrix = (int**)malloc(vertices * sizeof(int*));
    if (graph->matrix == NULL) {
        printf("Memory allocation failed\n");
        free(graph);
        return NULL;
    }
    
    for (int i = 0; i < vertices; i++) {
        graph->matrix[i] = (int*)calloc(vertices, sizeof(int));
        if (graph->matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(graph->matrix[j]);
            }
            free(graph->matrix);
            free(graph);
            return NULL;
        }
    }
    
    return graph;
}

// Add edge to graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    if (src >= 0 && src < graph->vertices && 
        dest >= 0 && dest < graph->vertices) {
        
        graph->matrix[src][dest] = weight;
        
        if (!graph->directed) {
            graph->matrix[dest][src] = weight;
        }
    }
}

// Remove edge from graph
void removeEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && 
        dest >= 0 && dest < graph->vertices) {
        
        graph->matrix[src][dest] = 0;
        
        if (!graph->directed) {
            graph->matrix[dest][src] = 0;
        }
    }
}

// Check if edge exists
bool hasEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && 
        dest >= 0 && dest < graph->vertices) {
        return graph->matrix[src][dest] != 0;
    }
    return false;
}

// Get edge weight
int getEdgeWeight(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && 
        dest >= 0 && dest < graph->vertices) {
        return graph->matrix[src][dest];
    }
    return -1;
}

// Print adjacency matrix
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < graph->vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < graph->vertices; j++) {
            printf("%2d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// Free graph memory
void freeGraph(Graph* graph) {
    if (graph != NULL) {
        if (graph->matrix != NULL) {
            for (int i = 0; i < graph->vertices; i++) {
                free(graph->matrix[i]);
            }
            free(graph->matrix);
        }
        free(graph);
    }
}
```

## Adjacency List Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Node structure for adjacency list
typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

// Adjacency list structure
typedef struct {
    AdjListNode* head;
} AdjList;

// Graph structure
typedef struct {
    int vertices;
    AdjList* array;
    bool directed;
} GraphList;

// Create new adjacency list node
AdjListNode* createAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Create graph with adjacency list
GraphList* createGraphList(int vertices, bool directed) {
    GraphList* graph = (GraphList*)malloc(sizeof(GraphList));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    graph->vertices = vertices;
    graph->directed = directed;
    
    // Create array of adjacency lists
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));
    if (graph->array == NULL) {
        printf("Memory allocation failed\n");
        free(graph);
        return NULL;
    }
    
    // Initialize all heads as NULL
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

// Add edge to graph
void addEdgeList(GraphList* graph, int src, int dest, int weight) {
    if (src >= 0 && src < graph->vertices && 
        dest >= 0 && dest < graph->vertices) {
        
        // Add edge from src to dest
        AdjListNode* newNode = createAdjListNode(dest, weight);
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;
        
        // If undirected, add edge from dest to src
        if (!graph->directed) {
            newNode = createAdjListNode(src, weight);
            newNode->next = graph->array[dest].head;
            graph->array[dest].head = newNode;
        }
    }
}

// Remove edge from graph
void removeEdgeList(GraphList* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && 
        dest >= 0 && dest < graph->vertices) {
        
        // Remove edge from src to dest
        AdjListNode* current = graph->array[src].head;
        AdjListNode* prev = NULL;
        
        while (current != NULL && current->dest != dest) {
            prev = current;
            current = current->next;
        }
        
        if (current != NULL) {
            if (prev == NULL) {
                graph->array[src].head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
        }
        
        // If undirected, remove edge from dest to src
        if (!graph->directed) {
            current = graph->array[dest].head;
            prev = NULL;
            
            while (current != NULL && current->dest != src) {
                prev = current;
                current = current->next;
            }
            
            if (current != NULL) {
                if (prev == NULL) {
                    graph->array[dest].head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
            }
        }
    }
}

// Print adjacency list
void printGraphList(GraphList* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: ", i);
        AdjListNode* current = graph->array[i].head;
        while (current != NULL) {
            printf("-> %d (w:%d) ", current->dest, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

// Free graph memory
void freeGraphList(GraphList* graph) {
    if (graph != NULL) {
        if (graph->array != NULL) {
            for (int i = 0; i < graph->vertices; i++) {
                AdjListNode* current = graph->array[i].head;
                while (current != NULL) {
                    AdjListNode* temp = current;
                    current = current->next;
                    free(temp);
                }
            }
            free(graph->array);
        }
        free(graph);
    }
}
```

## Graph Traversal

### 1. **Depth-First Search (DFS)**

```c
void DFS(Graph* graph, int start, bool* visited) {
    visited[start] = true;
    printf("%d ", start);
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[start][i] != 0 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

void DFSTraversal(Graph* graph, int start) {
    bool* visited = (bool*)calloc(graph->vertices, sizeof(bool));
    if (visited == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    printf("DFS starting from vertex %d: ", start);
    DFS(graph, start, visited);
    printf("\n");
    
    free(visited);
}
```

### 2. **Breadth-First Search (BFS)**

```c
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
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

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    
    return value;
}

void BFSTraversal(Graph* graph, int start) {
    bool* visited = (bool*)calloc(graph->vertices, sizeof(bool));
    if (visited == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    Queue queue;
    initializeQueue(&queue);
    
    visited[start] = true;
    enqueue(&queue, start);
    
    printf("BFS starting from vertex %d: ", start);
    
    while (!isEmpty(&queue)) {
        int current = dequeue(&queue);
        printf("%d ", current);
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->matrix[current][i] != 0 && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
    printf("\n");
    
    free(visited);
}
```

## Graph Algorithms

### 1. **Shortest Path - Dijkstra's Algorithm**

```c
#define INF 99999

int findMinDistance(int* distances, bool* visited, int vertices) {
    int min = INF;
    int minIndex = -1;
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && distances[i] <= min) {
            min = distances[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

void dijkstra(Graph* graph, int start) {
    int* distances = (int*)malloc(graph->vertices * sizeof(int));
    bool* visited = (bool*)calloc(graph->vertices, sizeof(bool));
    
    if (distances == NULL || visited == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Initialize distances
    for (int i = 0; i < graph->vertices; i++) {
        distances[i] = INF;
    }
    distances[start] = 0;
    
    for (int count = 0; count < graph->vertices - 1; count++) {
        int u = findMinDistance(distances, visited, graph->vertices);
        
        if (u == -1) break;
        
        visited[u] = true;
        
        for (int v = 0; v < graph->vertices; v++) {
            if (!visited[v] && graph->matrix[u][v] != 0 && 
                distances[u] != INF && 
                distances[u] + graph->matrix[u][v] < distances[v]) {
                distances[v] = distances[u] + graph->matrix[u][v];
            }
        }
    }
    
    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < graph->vertices; i++) {
        if (distances[i] == INF) {
            printf("Vertex %d: INF\n", i);
        } else {
            printf("Vertex %d: %d\n", i, distances[i]);
        }
    }
    
    free(distances);
    free(visited);
}
```

### 2. **Minimum Spanning Tree - Prim's Algorithm**

```c
void prim(Graph* graph) {
    int* parent = (int*)malloc(graph->vertices * sizeof(int));
    int* key = (int*)malloc(graph->vertices * sizeof(int));
    bool* mstSet = (bool*)calloc(graph->vertices, sizeof(bool));
    
    if (parent == NULL || key == NULL || mstSet == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Initialize keys
    for (int i = 0; i < graph->vertices; i++) {
        key[i] = INF;
    }
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < graph->vertices - 1; count++) {
        int u = findMinDistance(key, mstSet, graph->vertices);
        
        if (u == -1) break;
        
        mstSet[u] = true;
        
        for (int v = 0; v < graph->vertices; v++) {
            if (graph->matrix[u][v] != 0 && !mstSet[v] && 
                graph->matrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->matrix[u][v];
            }
        }
    }
    
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < graph->vertices; i++) {
        printf("%d - %d: %d\n", parent[i], i, graph->matrix[i][parent[i]]);
    }
    
    free(parent);
    free(key);
    free(mstSet);
}
```

## Complete Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 99999

typedef struct {
    int vertices;
    int** matrix;
    bool directed;
} Graph;

Graph* createGraph(int vertices, bool directed) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) return NULL;
    
    graph->vertices = vertices;
    graph->directed = directed;
    
    graph->matrix = (int**)malloc(vertices * sizeof(int*));
    if (graph->matrix == NULL) {
        free(graph);
        return NULL;
    }
    
    for (int i = 0; i < vertices; i++) {
        graph->matrix[i] = (int*)calloc(vertices, sizeof(int));
        if (graph->matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(graph->matrix[j]);
            }
            free(graph->matrix);
            free(graph);
            return NULL;
        }
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    if (src >= 0 && src < graph->vertices && 
        dest >= 0 && dest < graph->vertices) {
        graph->matrix[src][dest] = weight;
        if (!graph->directed) {
            graph->matrix[dest][src] = weight;
        }
    }
}

void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%2d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph) {
    if (graph != NULL) {
        if (graph->matrix != NULL) {
            for (int i = 0; i < graph->vertices; i++) {
                free(graph->matrix[i]);
            }
            free(graph->matrix);
        }
        free(graph);
    }
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices, false);
    
    // Add edges
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 4, 5);
    addEdge(graph, 3, 4, 1);
    
    printGraph(graph);
    
    freeGraph(graph);
    return 0;
}
```

## Applications of Graphs

1. **Social Networks**: Friend connections
2. **Transportation**: Road networks, flight routes
3. **Computer Networks**: Network topology
4. **Game Development**: Game maps, AI pathfinding
5. **Web Crawling**: Web page relationships
6. **Circuit Design**: Electronic circuit connections
7. **Dependency Resolution**: Software package dependencies

## Time Complexity

### Adjacency Matrix:
- **Add/Remove Edge**: O(1)
- **Check Edge**: O(1)
- **Traversal**: O(V²)
- **Space**: O(V²)

### Adjacency List:
- **Add/Remove Edge**: O(1)
- **Check Edge**: O(V)
- **Traversal**: O(V + E)
- **Space**: O(V + E)

Where V is number of vertices and E is number of edges. 