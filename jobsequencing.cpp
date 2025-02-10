// jobSequencing

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to represent a job
struct Job {
    char id;       // Job Id
    int dead;      // Deadline of job
    int profit;    // Profit if job is over before or on deadline
};

// Comparison function to sort jobs in decreasing order of profit
bool compare(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit from jobs
void printJobScheduling(vector<Job>& arr) {
    int n = arr.size();

    // Sort all jobs according to decreasing order of profit
    sort(arr.begin(), arr.end(), compare);

    vector<int> result(n, -1);  // To store result (sequence of jobs)
    vector<bool> slot(n, false); // To keep track of free time slots

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (start from the last possible slot)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            // Free slot found
            if (!slot[j]) {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    // Print the result (the sequence of jobs)
    cout << "Following is the maximum profit sequence of jobs:\n";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << arr[result[i]].id << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<Job> arr = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    // Function call
    printJobScheduling(arr);
}