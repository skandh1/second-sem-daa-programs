#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    // Step 1: Initialize distances from src to all other vertices as INFINITE
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles.
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print the calculated shortest distances
    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "         " << distance[i] << endl;
    }
}

int main() {
    int V, E, src;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(V, E, edges, src);

    return 0;
}
