#include <bits/stdc++.h>

// TC = O(n!);
// SC = O(n*n)

// adding board values to our final answer
void addAnswer(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
	vector<int> temp;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

// fucntion to find whether the placing queen in next column is safe or not
bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
	int x = row;
	int y = col;

	// checking in row
	while (y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		y--;
	}

	// checking for column is not required because we already placing one queen in one column only

	// checking for upper diagonal
	x = row;
	y = col;
	while (x >= 0 && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}

	// checking for lower diagonal
	x = row;
	y = col;
	while (x < n && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		x++;
		y--;
	}

	return true;
}

// fucntion to find the possible solution to place n queens
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
	// base case
	if (col == n) {
		addAnswer(board, ans, n);
		return ;
	}

	for (int row=0; row<n; row++) {
		if (isSafe(row, col, board, n)) {
			board[row][col] = 1;
			solve(col+1, board, ans, n);
			board[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n) {
	// Write your code here
	vector<vector<int>> board(n, vector<int> (n, 0));
	vector<vector<int>> ans;
	solve(0, board, ans, n);
	return ans;
}