#include <iostream>
#include <vector>
#include <algorithm>

// Function to solve 0/1 Knapsack problem using recursion
int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    // Base Case: If no items are left or capacity is 0
    if (n == 0 || W == 0) {
        return 0;
    }

    // If weight of the nth item is more than Knapsack capacity W, then this item cannot be included
    if (weights[n-1] > W) {
        return knapsack(W, weights, values, n-1);
    } else {
        // Return the maximum of two cases:
        // 1. nth item included
        // 2. not included
        return std::max(
            values[n-1] + knapsack(W - weights[n-1], weights, values, n-1),
            knapsack(W, weights, values, n-1)
        );
    }
}

int main() {
    std::vector<int> values = {60, 100, 120};
    std::vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    std::cout << "Maximum value in Knapsack: " << knapsack(W, weights, values, n) << std::endl;

    return 0;
}
