// adjcencyList

#include <bits/stdc++.h>
using namespace std;

// DFS function
void DFS(int node, vector<int>& visited, vector<int> adjList[]) {
    visited[node] = 1;
    cout << node << " ";

    for (auto child : adjList[node]) {
        if (visited[child] == 0) {
            DFS(child, visited, adjList);
        }
    }
}

// BFS function
void BFS(int node, vector<int>& visited, vector<int> adjList[]) {
    queue<int> Q;
    Q.push(node);
    visited[node] = 1;

    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        cout << current << " ";

        for (auto neighbor : adjList[current]) {
            if (visited[neighbor] == 0) {
                Q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adjList[nodes + 1]; // Adjacency list for 1-based indexing

    // Read the edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> visited(nodes + 1, 0);

    // Run DFS and BFS for each component of the graph
    cout << "DFS traversal:\n";
    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            DFS(i, visited, adjList);
            cout << endl; // New line for each connected component
        }
    }

    fill(visited.begin(), visited.end(), 0); // Reset visited for BFS

    cout << "BFS traversal:\n";
    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            BFS(i, visited, adjList);
            cout << endl; // New line for each connected component
        }
    }
}

// OUTPUT:
// Enter the number of vertices: 4
// Enter the number of edges: 5
// Enter the edges (u v):
// 1 2
// 2 3
// 3 4
// 1 3
// 2 4
// Enter the starting vertex for traversal: 2
// BFT: 2 4 3 1
// DFT: 2 3 1 4