#include <stdio.h>
#include <stdbool.h>

#define N 10 // Change N to the desired chessboard size

int board[N][N] = {0}; // Initialize the chessboard

// Function to print the chessboard
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int row, int col) {
    // Check the left side of this row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve N-Queens problem using backtracking
bool solveNQueens(int col) {
    if (col == N) {
        // All queens are placed successfully
        // Print the solution and return true
        printBoard();
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            res = solveNQueens(col + 1) || res;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove the queen (backtrack)
            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

int main() {
    if (solveNQueens(0) == false) {
        printf("No solution exists for N = %d\n", N);
    }

    return 0;
}
