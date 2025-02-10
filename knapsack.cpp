// knapsack

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Create a 2D table to store the maximum values for subproblems
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));  // Using vector initialization

    // Build table K[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    
    // Return the last cell which contains the maximum profit
    return K[n][W];
}

// Driver code
int main() {
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;  // Capacity of the knapsack
    int n = profit.size();  // Number of items
    
    // Function call and print the result
    cout << knapSack(W, weight, profit, n) << endl;
}