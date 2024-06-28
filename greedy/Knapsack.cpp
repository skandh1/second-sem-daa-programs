#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Item structure to store weight and value of each item
struct Item {
    int value, weight;

    // Constructor
    Item(int value, int weight) : value(value), weight(weight) {}
};

// Comparison function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value that can be obtained
double fractionalKnapsack(int W, vector<Item> items) {
    sort(items.begin(), items.end(), compare);

    int curWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Result (value in knapsack)

    for (auto &item : items) {
        if (curWeight + item.weight <= W) {
            curWeight += item.weight;
            finalValue += item.value;
        } else {
            int remain = W - curWeight;
            finalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 50; // Knapsack capacity
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, items) << endl;

    return 0;
}
