#include <iostream>
#include <vector>

using namespace std;

// Function to print the current subset
void printSubset(const vector<int>& subset) {
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}

// Backtracking function to find subsets that sum to the given target
void sumOfSubsets(vector<int>& nums, int target, vector<int>& currentSubset, int currentIndex, int currentSum) {
    if (currentSum == target) {
        printSubset(currentSubset);
        return;
    }

    if (currentIndex >= nums.size() || currentSum > target) {
        return;
    }

    // Include the current element
    currentSubset.push_back(nums[currentIndex]);
    sumOfSubsets(nums, target, currentSubset, currentIndex + 1, currentSum + nums[currentIndex]);

    // Exclude the current element (backtrack)
    currentSubset.pop_back();
    sumOfSubsets(nums, target, currentSubset, currentIndex + 1, currentSum);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> currentSubset;
    cout << "Subsets with sum " << target << " are:" << endl;
    sumOfSubsets(nums, target, currentSubset, 0, 0);

    return 0;
}
