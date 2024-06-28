#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent items
struct Item
{
    int weight;
    int value;
};

// Function to compare items by their value per unit weight (value/weight ratio)
bool compareItems(const Item &a, const Item &b)
{
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}

// Function to solve 0/1 Knapsack using Branch and Bound
int knapsackBranchBound(int capacity, const vector<Item> &items, int n)
{
    // Sort items by value/weight ratio (decreasing order)
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareItems);

    int maxProfit = 0;
    int currentWeight = 0;
    int currentProfit = 0;

    // Function to compute upper bound using fractional knapsack approach
    auto computeBound = [&](int level, int weight, int profit) -> int
    {
        if (weight >= capacity)
            return profit;

        int bound = profit;
        int remainingWeight = capacity - weight;

        // Add fractional part of next item to the bound
        for (int i = level; i < n; ++i)
        {
            if (sortedItems[i].weight <= remainingWeight)
            {
                remainingWeight -= sortedItems[i].weight;
                bound += sortedItems[i].value;
            }
            else
            {
                bound += sortedItems[i].value * ((double)remainingWeight / sortedItems[i].weight);
                break;
            }
        }

        return bound;
    };

    // Initialize priority queue for branch and bound
    vector<pair<int, int>> pq; // pair of (bound, level)
    pq.push_back({0, 0});

    while (!pq.empty())
    {
        int bound = pq.back().first;
        int level = pq.back().second;
        pq.pop_back();

        // If current bound is less than maxProfit, prune the subtree
        if (bound <= maxProfit)
            continue;

        // If we reached the end of the items list, update maxProfit if possible
        if (level == n)
        {
            maxProfit = max(maxProfit, currentProfit);
            continue;
        }

        // Consider the next level (left child) - item is included in knapsack
        if (currentWeight + sortedItems[level].weight <= capacity)
        {
            currentWeight += sortedItems[level].weight;
            currentProfit += sortedItems[level].value;

            // Update bound and push to priority queue
            bound = computeBound(level + 1, currentWeight, currentProfit);
            pq.push_back({bound, level + 1});

            // Backtrack
            currentWeight -= sortedItems[level].weight;
            currentProfit -= sortedItems[level].value;
        }

        // Consider the next level (right child) - item is not included in knapsack
        bound = computeBound(level + 1, currentWeight, currentProfit);
        pq.push_back({bound, level + 1});
    }

    return maxProfit;
}

// Example usage
int main()
{
    vector<Item> items = {{2, 40}, {3, 50}, {5, 100}, {7, 95}};
    int capacity = 10;
    int n = items.size();

    int maxProfit = knapsackBranchBound(capacity, items, n);

    cout << "Maximum profit (using Branch and Bound): " << maxProfit << endl;

    return 0;
}
