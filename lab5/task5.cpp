#include <iostream>
using namespace std;

const int MAX_N = 20;
int board[MAX_N][MAX_N]; 

// Function to print the chessboard with queens placed
void printBoard(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at a given position
bool isSafe(int row, int col, int N) {
    // Check column for any queen
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(int row, int N) {
    if (row >= N)
        return true; // All queens are placed

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, N)) {
            board[row][col] = 1; // Place queen

            // Recursively attempt to place the next queen
            if (solveNQueens(row + 1, N))
                return true;

            // Backtrack and remove the queen
            board[row][col] = 0;
        }
    }

    return false; // No solution found for the current configuration
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    // Initialize the chessboard
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    // Attempt to solve the N-Queens problem
    if (!solveNQueens(0, N)) {
        cout << "No solution exists." << endl;
    } else {
        printBoard(N); // Print the solution
    }

    return 0;
}
