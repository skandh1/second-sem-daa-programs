#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS on a graph
void DFS(int node, const vector<vector<int>>& adjList, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    cout << "Visited node: " << node << endl;

    // Visit all the adjacent nodes
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited);
        }
    }
}

int main() {
    // Number of nodes in the graph
    int numNodes = 5;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(numNodes);

    // Adding edges to the graph (undirected for this example)
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[2].push_back(0);
    adjList[2].push_back(4);
    adjList[3].push_back(1);
    adjList[4].push_back(2);

    // Vector to keep track of visited nodes
    vector<bool> visited(numNodes, false);

    // Start DFS from node 0
    DFS(0, adjList, visited);

    return 0;
}
