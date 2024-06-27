#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Structure to represent a job
struct Job {
    char id;      // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit of the job
};

// Function to compare jobs based on profit (used for sorting)
bool compareJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to schedule jobs with deadlines using greedy approach
void jobSequencing(Job jobs[], int n) {
    // Sort jobs based on profit (in descending order)
    sort(jobs, jobs + n, compareJobs);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Array to store result (scheduled jobs)
    char result[maxDeadline] = {0};

    // Schedule jobs
    int totalProfit = 0;
    for (int i = 0; i < n; ++i) {
        // Find a slot for this job (from end to beginning)
        for (int j = jobs[i].deadline - 1; j >= 0; --j) {
            if (result[j] == 0) { // Slot is available
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the scheduled jobs and total profit
    cout << "Scheduled jobs with deadlines using greedy approach:" << endl;
    for (int i = 0; i < maxDeadline; ++i) {
        if (result[i] != 0) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
    cout << "Total profit: " << totalProfit << endl;
}

// Main function
int main() {
    // Example jobs
    Job jobs[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Call function to schedule jobs
    jobSequencing(jobs, n);

    return 0;
}
