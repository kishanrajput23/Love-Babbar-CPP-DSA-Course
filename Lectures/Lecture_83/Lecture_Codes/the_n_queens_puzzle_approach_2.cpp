#include <bits/stdc++.h> 

/*
TC = O(n!);
SC = O(n*n)

Using a map to track the positions of queens can indeed be a more efficient approach than iterating over the entire board repeatedly. 
We can use two maps to store the positions of queens along the rows and diagonals. 
*/

// Function to add the board configuration to the final answer
void addAnswer(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    vector<int> temp;

    // Convert 2D board to 1D vector
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    // Add the configuration to the answer
    ans.push_back(temp);
}

// Function to check if placing a queen at a given position is safe
bool isSafe(int row, int col, unordered_map<int, int> &rows, unordered_map<int, int> &left_diagonal, unordered_map<int, int> &right_diagonal) {
    
	// Check if the current row, left diagonal, or right diagonal is occupied
    if (rows.count(row) || left_diagonal.count(row - col) || right_diagonal.count(row + col)) {
        return false;
	}

    return true; 
}

// Recursive function to find solutions for N-Queens problem
void solve(int col, vector<vector<int>> &board, unordered_map<int, int> &rows, unordered_map<int, int> &left_diagonal, unordered_map<int, int> &right_diagonal, vector<vector<int>> &ans, int n) {
    
	// Base case: all queens are placed
    if (col == n) {
        addAnswer(board, ans, n); // Add the current board configuration to the answer
        return;
    }

    // Try placing the queen in each row of the current column
    for (int row = 0; row < n; row++) {

        // Check if it's safe to place the queen at the current position
        if (isSafe(row, col, rows, left_diagonal, right_diagonal)) {

            // Place the queen
            board[row][col] = 1;

            // Update occupied rows and diagonals
            rows[row] = 1;
            left_diagonal[row - col] = 1;
            right_diagonal[row + col] = 1;

            // Recursively solve for the next column
            solve(col + 1, board, rows, left_diagonal, right_diagonal, ans, n);

            // Backtrack: remove the queen and update occupied rows and diagonals
            board[row][col] = 0;
            rows.erase(row);
            left_diagonal.erase(row - col);
            right_diagonal.erase(row + col);
        }
    }
}

// Function to find all solutions to the N-Queens problem
vector<vector<int>> nQueens(int n) {
	 // Initialize empty board
    vector<vector<int>> board(n, vector<int>(n, 0));

	// Maps to track occupied rows and diagonals
    unordered_map<int, int> rows, left_diagonal, right_diagonal; 

	// Vector to store all solutions
    vector<vector<int>> ans; 

    solve(0, board, rows, left_diagonal, right_diagonal, ans, n);

    return ans;
}