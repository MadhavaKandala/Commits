// adjanceyMatrix

#include <iostream>
#include <queue>
#define MAX 100  // Maximum number of vertices

using namespace std;

int adjMatrix[MAX][MAX];  // Adjacency Matrix
int visited[MAX];         // Visited array for traversal

// Function to add an edge to the graph (Adjacency Matrix)
void addEdgeMatrix(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;  // For undirected graph
}

// Breadth-First Traversal using Adjacency Matrix
void BFTMatrix(int start, int n) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    cout << "BFT: ";
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";
        
        for (int i = 0; i < n; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// Depth-First Traversal using Adjacency Matrix
void DFTMatrix(int vertex, int n) {
    visited[vertex] = 1;
    cout << vertex << " ";
    
    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFTMatrix(i, n);
        }
    }
}

void resetVisited(int n) { // Reset visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

int main() {
    int n, edges;

    // Input the number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Initialize the adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input the edges of the graph
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        addEdgeMatrix(u, v);
    }

    // Input the starting vertex for traversal
    cout << "Enter the starting vertex for traversal: ";
    int start;
    cin >> start;

    // Perform Breadth-First Traversal (BFT)
    resetVisited(n);
    BFTMatrix(start, n);

    // Perform Depth-First Traversal (DFT)
    resetVisited(n);
    cout << "DFT: ";
    DFTMatrix(start, n);
    cout << endl;
}

// OUTPUT:
// Enter the number of vertices: 4
// Enter the number of edges: 4
// Enter the edges (u v):
// 1 2
// 1 3
// 2 4
// 3 4
// Enter the starting vertex for traversal: 1
// BFT: 1 2 3
// DFT: 1 2 3