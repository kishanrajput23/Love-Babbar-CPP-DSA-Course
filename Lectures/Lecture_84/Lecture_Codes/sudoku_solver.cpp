#include <bits/stdc++.h> 

// Function to check if it's safe to place a value at a given position
bool isSafe(int row, int col, vector<vector<int>>& sudoku, int val) {
    for (int i=0; i<sudoku.size(); i++) {
        if (sudoku[row][i] == val) {
            return false;
        }

        if (sudoku[i][col] == val) {
            return false;
        }

        if (sudoku[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == val) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve Sudoku
bool solve(vector<vector<int>>& sudoku) {
    int n = sudoku.size();

    for (int row=0; row<n; row++) {
        for (int col=0; col<n; col++) {

            // If the cell is empty
            if (sudoku[row][col] == 0) {

                // Try placing values from 1 to 9
                for (int val=1; val<=9; val++) {

                    // Check if it's safe to place val at the current position
                    if (isSafe(row, col, sudoku, val)) {
                        sudoku[row][col] = val;
                        
                        // Recursively try to solve the Sudoku
                        bool nextPossibleSolution = solve(sudoku);

                        // If a solution is found, return true
                        if (nextPossibleSolution) {
                            return true;
                        }
                        else {
                            sudoku[row][col] = 0;       // Backtrack if no solution found
                        }
                    }
                }
                return false;       // If no valid value can be placed, return false
            }
        }
    }
    return true;        // If all cells are filled, return true (base case)
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}