#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity value for unreachable nodes

// Structure to represent a graph edge
struct Edge
{
    int to;
    int weight;
};

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<Edge>> &graph, int start, vector<int> &dist)
{
    int n = graph.size();
    dist.assign(n, INF);
    dist[start] = 0;

    // Min-heap priority queue to efficiently get the node with the smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If the extracted vertex 'u' has already been processed, skip it
        if (d > dist[u])
            continue;

        // Explore all neighboring vertices of u
        for (const Edge &e : graph[u])
        {
            int v = e.to;
            int weight = e.weight;

            // Relaxation step: Update the distance if a shorter path is found
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

// Example usage
int main()
{
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    // Reading the graph input
    for (int i = 0; i < m; ++i)
    {
        int u, v, w; // Edge from u to v with weight w
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // For undirected graph, include the reverse edge as well
        // graph[v].push_back({u, w});
    }

    int start; // Starting vertex for Dijkstra's algorithm
    cin >> start;

    vector<int> dist;
    dijkstra(graph, start, dist);

    // Output the shortest paths from the start vertex to all other vertices
    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == INF)
        {
            cout << i << ": INF\n";
        }
        else
        {
            cout << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}
