#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Find function for union-find with path compression
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

// Union function for union-find by rank
void unionSet(vector<Subset>& subsets, int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    // Union by rank
    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Kruskal's algorithm to find MST
void kruskalMST(vector<Edge>& edges, int V) {
    // Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<Edge> result; // To store the resultant MST
    vector<Subset> subsets(V);

    // Initialize subsets for union-find
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0; // Index variable used for sorted edges
    int i = 0; // Index variable used for result[]

    // Number of edges to be taken is equal to V-1
    while (i < V - 1 && e < edges.size()) {
        // Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far
        Edge nextEdge = edges[e++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does not cause a cycle, include it in the result and increment the index of result for next edge
        if (x != y) {
            result.push_back(nextEdge);
            unionSet(subsets, x, y);
            ++i;
        }
        // Otherwise, discard the edge
    }

    // Print the edges of MST
    cout << "Edges of Minimum Spanning Tree using Kruskal's algorithm:\n";
    for (const auto& edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

// Example usage
int main() {
    int V = 4; // Number of vertices in graph
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V);

    return 0;
}
