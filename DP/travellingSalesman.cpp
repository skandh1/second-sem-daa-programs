#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

const int INF = INT_MAX;

// Function to solve the Travelling Salesman Problem using DP and bit masking
int tsp(int mask, int pos, std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& dp) {
    int n = dist.size();

    // If all cities have been visited, return the distance to the start city
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    // If the subproblem has already been solved, return the stored result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Try to visit all the unvisited cities and find the minimum cost
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // If the city has not been visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            ans = std::min(ans, newAns);
        }
    }

    // Store the result and return it
    return dp[mask][pos] = ans;
}

int main() {
    // Adjacency matrix for the distances between cities
    std::vector<std::vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };

    int n = dist.size();
    // DP table to store the results of subproblems
    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, -1));

    // Start the TSP from the first city with a mask indicating only the first city is visited
    int result = tsp(1, 0, dist, dp);

    std::cout << "The minimum cost to visit all cities: " << result << std::endl;

    return 0;
}
