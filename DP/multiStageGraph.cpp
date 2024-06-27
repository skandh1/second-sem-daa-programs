#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

// Function to find the shortest path in a multistage graph
int shortestPath(vector<vector<int>>& graph, int stages) {
    int n = graph.size();
    vector<int> cost(n, INF);
    vector<int> path(n, -1);

    // Cost of reaching the destination node is 0
    cost[n-1] = 0;

    // Calculate cost for each node starting from the second last node to the source
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] != INF) {
                if (cost[i] > graph[i][j] + cost[j]) {
                    cost[i] = graph[i][j] + cost[j];
                    path[i] = j;
                }
            }
        }
    }

    // Print the shortest path
    cout << "The shortest path is: ";
    int current = 0;
    while (current != -1) {
        cout << current << " ";
        current = path[current];
    }
    cout << endl;

    return cost[0];
}

int main() {
    // Number of stages
    int stages = 4;

    // Adjacency matrix representing the multistage graph
    vector<vector<int>> graph = {
        {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF}
    };

    int shortest_cost = shortestPath(graph, stages);

    cout << "The cost of the shortest path is: " << shortest_cost << endl;

    return 0;
}
