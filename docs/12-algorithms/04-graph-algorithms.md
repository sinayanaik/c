# Graph Algorithms in C Programming

## Overview

Graph algorithms are fundamental algorithms that operate on graph data structures. They are essential for solving problems involving networks, relationships, and connectivity. Graph algorithms are used in various applications like social networks, transportation systems, and computer networks.

## Types of Graph Algorithms

### 1. **Traversal Algorithms**
Algorithms that visit all vertices and edges of a graph.

### 2. **Shortest Path Algorithms**
Algorithms that find the shortest path between vertices.

### 3. **Minimum Spanning Tree Algorithms**
Algorithms that find the minimum spanning tree of a graph.

### 4. **Connectivity Algorithms**
Algorithms that determine connectivity properties of graphs.

## Graph Representation

### Adjacency Matrix Implementation

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

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
            for (int j = 0; j < i; j++) {
                free(graph->matrix[j]);
            }
            free(graph->matrix);
            free(graph);
            return NULL;
        }
    }
    
    // Initialize with INF for no edge
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i != j) {
                graph->matrix[i][j] = INF;
            }
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

// Print graph
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
            if (graph->matrix[i][j] == INF) {
                printf(" ∞ ");
            } else {
                printf("%2d ", graph->matrix[i][j]);
            }
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

## Graph Traversal Algorithms

### 1. **Depth-First Search (DFS)**

```c
void DFS(Graph* graph, int start, bool* visited) {
    visited[start] = true;
    printf("%d ", start);
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[start][i] != INF && !visited[i]) {
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
            if (graph->matrix[current][i] != INF && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
    printf("\n");
    
    free(visited);
}
```

## Shortest Path Algorithms

### 1. **Dijkstra's Algorithm**

```c
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
            if (!visited[v] && graph->matrix[u][v] != INF && 
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

### 2. **Bellman-Ford Algorithm**

```c
bool bellmanFord(Graph* graph, int start) {
    int* distances = (int*)malloc(graph->vertices * sizeof(int));
    if (distances == NULL) {
        printf("Memory allocation failed\n");
        return false;
    }
    
    // Initialize distances
    for (int i = 0; i < graph->vertices; i++) {
        distances[i] = INF;
    }
    distances[start] = 0;
    
    // Relax all edges |V| - 1 times
    for (int i = 1; i < graph->vertices; i++) {
        for (int u = 0; u < graph->vertices; u++) {
            for (int v = 0; v < graph->vertices; v++) {
                if (graph->matrix[u][v] != INF && 
                    distances[u] != INF && 
                    distances[u] + graph->matrix[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph->matrix[u][v];
                }
            }
        }
    }
    
    // Check for negative weight cycles
    for (int u = 0; u < graph->vertices; u++) {
        for (int v = 0; v < graph->vertices; v++) {
            if (graph->matrix[u][v] != INF && 
                distances[u] != INF && 
                distances[u] + graph->matrix[u][v] < distances[v]) {
                printf("Graph contains negative weight cycle\n");
                free(distances);
                return false;
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
    return true;
}
```

### 3. **Floyd-Warshall Algorithm**

```c
void floydWarshall(Graph* graph) {
    int** dist = (int**)malloc(graph->vertices * sizeof(int*));
    if (dist == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    for (int i = 0; i < graph->vertices; i++) {
        dist[i] = (int*)malloc(graph->vertices * sizeof(int));
        if (dist[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(dist[j]);
            }
            free(dist);
            return;
        }
    }
    
    // Initialize distance matrix
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            dist[i][j] = graph->matrix[i][j];
        }
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < graph->vertices; k++) {
        for (int i = 0; i < graph->vertices; i++) {
            for (int j = 0; j < graph->vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Print shortest distances
    printf("All-pairs shortest paths:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (dist[i][j] == INF) {
                printf("∞ ");
            } else {
                printf("%2d ", dist[i][j]);
            }
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 0; i < graph->vertices; i++) {
        free(dist[i]);
    }
    free(dist);
}
```

## Minimum Spanning Tree Algorithms

### 1. **Prim's Algorithm**

```c
int findMinKey(int* key, bool* mstSet, int vertices) {
    int min = INF;
    int minIndex = -1;
    
    for (int i = 0; i < vertices; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

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
        int u = findMinKey(key, mstSet, graph->vertices);
        
        if (u == -1) break;
        
        mstSet[u] = true;
        
        for (int v = 0; v < graph->vertices; v++) {
            if (graph->matrix[u][v] != INF && !mstSet[v] && 
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

### 2. **Kruskal's Algorithm**

```c
// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Structure for subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// Find set of an element
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union of two sets
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal(Graph* graph) {
    int V = graph->vertices;
    int E = 0;
    
    // Count edges
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph->matrix[i][j] != INF) {
                E++;
            }
        }
    }
    
    Edge* edges = (Edge*)malloc(E * sizeof(Edge));
    if (edges == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Create edge list
    int edgeIndex = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph->matrix[i][j] != INF) {
                edges[edgeIndex].src = i;
                edges[edgeIndex].dest = j;
                edges[edgeIndex].weight = graph->matrix[i][j];
                edgeIndex++;
            }
        }
    }
    
    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), compareEdges);
    
    // Allocate memory for result
    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));
    if (result == NULL) {
        free(edges);
        return;
    }
    
    // Allocate memory for subsets
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    if (subsets == NULL) {
        free(edges);
        free(result);
        return;
    }
    
    // Create V subsets with single elements
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    int resultIndex = 0;
    int edgeIndex2 = 0;
    
    while (resultIndex < V - 1 && edgeIndex2 < E) {
        Edge nextEdge = edges[edgeIndex2++];
        
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        
        if (x != y) {
            result[resultIndex++] = nextEdge;
            Union(subsets, x, y);
        }
    }
    
    printf("Minimum Spanning Tree (Kruskal):\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    
    free(edges);
    free(result);
    free(subsets);
}
```

## Connectivity Algorithms

### 1. **Connected Components**

```c
void DFSConnected(Graph* graph, int start, bool* visited, int* component, int componentId) {
    visited[start] = true;
    component[start] = componentId;
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[start][i] != INF && !visited[i]) {
            DFSConnected(graph, i, visited, component, componentId);
        }
    }
}

void findConnectedComponents(Graph* graph) {
    bool* visited = (bool*)calloc(graph->vertices, sizeof(bool));
    int* component = (int*)malloc(graph->vertices * sizeof(int));
    
    if (visited == NULL || component == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    int componentId = 0;
    
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            DFSConnected(graph, i, visited, component, componentId);
            componentId++;
        }
    }
    
    printf("Connected Components:\n");
    for (int i = 0; i < componentId; i++) {
        printf("Component %d: ", i);
        for (int j = 0; j < graph->vertices; j++) {
            if (component[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    
    free(visited);
    free(component);
}
```

### 2. **Articulation Points (Cut Vertices)**

```c
void findArticulationPoints(Graph* graph) {
    bool* visited = (bool*)calloc(graph->vertices, sizeof(bool));
    int* disc = (int*)malloc(graph->vertices * sizeof(int));
    int* low = (int*)malloc(graph->vertices * sizeof(int));
    int* parent = (int*)malloc(graph->vertices * sizeof(int));
    bool* ap = (bool*)calloc(graph->vertices, sizeof(bool));
    
    if (visited == NULL || disc == NULL || low == NULL || parent == NULL || ap == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Initialize arrays
    for (int i = 0; i < graph->vertices; i++) {
        parent[i] = -1;
        disc[i] = -1;
        low[i] = -1;
    }
    
    // Find articulation points using DFS
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            findArticulationPointsUtil(graph, i, visited, disc, low, parent, ap);
        }
    }
    
    printf("Articulation Points: ");
    for (int i = 0; i < graph->vertices; i++) {
        if (ap[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    free(visited);
    free(disc);
    free(low);
    free(parent);
    free(ap);
}

void findArticulationPointsUtil(Graph* graph, int u, bool* visited, int* disc, int* low, int* parent, bool* ap) {
    static int time = 0;
    int children = 0;
    
    visited[u] = true;
    disc[u] = low[u] = ++time;
    
    for (int v = 0; v < graph->vertices; v++) {
        if (graph->matrix[u][v] != INF) {
            if (!visited[v]) {
                children++;
                parent[v] = u;
                findArticulationPointsUtil(graph, v, visited, disc, low, parent, ap);
                
                low[u] = min(low[u], low[v]);
                
                if (parent[u] == -1 && children > 1) {
                    ap[u] = true;
                }
                
                if (parent[u] != -1 && low[v] >= disc[u]) {
                    ap[u] = true;
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
}
```

## Complete Example

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

// Function declarations
Graph* createGraph(int vertices, bool directed);
void addEdge(Graph* graph, int src, int dest, int weight);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);
void DFSTraversal(Graph* graph, int start);
void BFSTraversal(Graph* graph, int start);
void dijkstra(Graph* graph, int start);
bool bellmanFord(Graph* graph, int start);
void floydWarshall(Graph* graph);
void prim(Graph* graph);
void kruskal(Graph* graph);
void findConnectedComponents(Graph* graph);

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    printf("=== Graph Algorithms Examples ===\n\n");
    
    // Create a weighted undirected graph
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
    
    printf("Graph:\n");
    printGraph(graph);
    printf("\n");
    
    // Graph traversal
    DFSTraversal(graph, 0);
    BFSTraversal(graph, 0);
    
    // Shortest path algorithms
    printf("\n=== Shortest Path Algorithms ===\n");
    dijkstra(graph, 0);
    
    // Minimum spanning tree
    printf("\n=== Minimum Spanning Tree ===\n");
    prim(graph);
    
    // Connected components
    printf("\n=== Connectivity ===\n");
    findConnectedComponents(graph);
    
    freeGraph(graph);
    return 0;
}
```

### Output

```
=== Graph Algorithms Examples ===

Graph:
Adjacency Matrix:
    0  1  2  3  4 
 0  0  2  4  ∞  ∞ 
 1  2  0  1  7  ∞ 
 2  4  1  0  3  5 
 3  ∞  7  3  0  1 
 4  ∞  ∞  5  1  0 

DFS starting from vertex 0: 0 1 2 3 4 
BFS starting from vertex 0: 0 1 2 3 4 

=== Shortest Path Algorithms ===
Shortest distances from vertex 0:
Vertex 0: 0
Vertex 1: 2
Vertex 2: 3
Vertex 3: 6
Vertex 4: 7

=== Minimum Spanning Tree ===
Minimum Spanning Tree:
0 - 1: 2
1 - 2: 1
2 - 3: 3
3 - 4: 1

=== Connectivity ===
Connected Components:
Component 0: 0 1 2 3 4 
```

## Applications of Graph Algorithms

1. **Social Networks**: Friend suggestions, community detection
2. **Transportation**: Route planning, traffic optimization
3. **Computer Networks**: Network routing, topology analysis
4. **Game Development**: AI pathfinding, game maps
5. **Bioinformatics**: Protein interaction networks
6. **Web Crawling**: Page ranking, link analysis
7. **Circuit Design**: Electronic circuit optimization

## Time Complexity Comparison

| Algorithm | Time Complexity | Space Complexity | Use Case |
|-----------|----------------|------------------|----------|
| DFS | O(V + E) | O(V) | Traversal, connectivity |
| BFS | O(V + E) | O(V) | Shortest path (unweighted) |
| Dijkstra | O(V²) | O(V) | Shortest path (weighted, no negative edges) |
| Bellman-Ford | O(VE) | O(V) | Shortest path (weighted, with negative edges) |
| Floyd-Warshall | O(V³) | O(V²) | All-pairs shortest paths |
| Prim | O(V²) | O(V) | Minimum spanning tree |
| Kruskal | O(E log E) | O(V) | Minimum spanning tree |

## When to Use Each Algorithm

### **DFS**
- Graph traversal
- Connected components
- Topological sorting
- Cycle detection

### **BFS**
- Shortest path (unweighted graphs)
- Level-order traversal
- Web crawling
- Social network analysis

### **Dijkstra**
- Shortest path in weighted graphs
- No negative edge weights
- Single-source shortest path

### **Bellman-Ford**
- Shortest path with negative edges
- Negative cycle detection
- Single-source shortest path

### **Floyd-Warshall**
- All-pairs shortest paths
- Small graphs
- Transitive closure

### **Prim/Kruskal**
- Minimum spanning tree
- Network design
- Clustering algorithms 