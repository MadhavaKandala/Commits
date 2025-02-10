// nQueens

#include <iostream>
#include <vector>
using namespace std;

// Chessboard (2D vector)
vector<vector<int>> board;
int n; // Size of the board

// Function to print the board
void printBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Backtracking function to solve the N-Queens problem
bool solveNQueens(int row) {
    // Base case: If all queens are placed
    if (row >= n) {
        printBoard(); // Print the solution
        return true;  // Returning true just for this implementation, modify if you want all solutions
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1; // Place the queen
            // Recur to place the rest of the queens
            if (solveNQueens(row + 1)) {
                return true;
            }
            // Backtrack: Remove the queen
            board[row][col] = 0;
        }
    }
    
    return false; // No solution found
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> n;

    // Initialize the board as a 2D vector of size n x n
    board.assign(n, vector<int>(n, 0));

    // Solve the N-Queens problem
    if (!solveNQueens(0)) {
        cout << "Solution does not exist." << endl;
    }
}