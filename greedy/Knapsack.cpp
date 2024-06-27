#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

bool cmpRatio(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<Item> items(n);

    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), cmpRatio);

    int totalValue = 0;
    double totalWeight = 0.0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            totalWeight += items[i].weight;
        } else {
            break;
        }
    }

    cout << "Maximum value that can be put in the knapsack: " << totalValue << endl;
    cout << "Total weight in the knapsack: " << totalWeight << endl;

    return 0;
}