#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to find the optimal binary search tree cost
float optimalBSTCost(const vector<float>& keys, const vector<float>& freq) {
    int n = keys.size();
    vector<vector<float>> cost(n, vector<float>(n, 0));

    // Base case: single node trees
    for (int i = 0; i < n; ++i) {
        cost[i][i] = freq[i];
    }

    // Build the cost table in a bottom-up manner
    for (int L = 2; L <= n; ++L) {  // L is chain length
        for (int i = 0; i <= n - L + 1; ++i) {
            int j = i + L - 1;
            cost[i][j] = numeric_limits<float>::infinity();
            float sum = 0;

            // Calculate sum of freq[i] to freq[j]
            for (int k = i; k <= j; ++k) {
                sum += freq[k];
            }

            // Try making all keys in interval keys[i..j] as root
            for (int k = i; k <= j; ++k) {
                float val = ((k > i) ? cost[i][k - 1] : 0) +
                            ((k < j) ? cost[k + 1][j] : 0) + sum;
                if (val < cost[i][j]) {
                    cost[i][j] = val;
                }
            }
        }
    }

    // Return the optimal cost of BST
    return cost[0][n - 1];
}

int main() {
    vector<float> keys = {10, 12, 20};
    vector<float> freq = {4, 2, 6};

    float minCost = optimalBSTCost(keys, freq);

    cout << "The cost of optimal BST is: " << minCost << endl;

    return 0;
}
