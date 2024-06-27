#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity value for unreachable nodes

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(const vector<vector<int>>& graph, int n) {
    vector<int> parent(n, -1); // Array to store constructed MST
    vector<int> key(n, INF);   // Key values used to pick minimum weight edge in cut
    vector<bool> inMST(n, false); // To represent set of vertices not yet included in MST

    // Start with vertex 0
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // Construct MST with (n-1) edges
    for (int count = 0; count < n - 1; ++count) {
        // Find the vertex with minimum key value from the set of vertices not yet included in MST
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        // Add the picked vertex to the MST set
        inMST[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Example usage
int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int n = graph.size(); // Number of vertices

    primMST(graph, n);

    return 0;
}
