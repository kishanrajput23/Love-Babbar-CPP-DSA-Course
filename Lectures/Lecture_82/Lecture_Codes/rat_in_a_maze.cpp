#include <bits/stdc++.h> 

// TC = O(4 ^ (n^2)) 
// SC = O(n*m) where n and m are refers to no of rows and columns

bool isSafe(int newX, int newY, vector<vector<int>> &arr, vector<vector<bool>> &visited, int n) {
    if ((newX >=0 && newX < n) && (newY >= 0 && newY < n) && visited[newX][newY] != 1 && arr[newX][newY] != 0) {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<string> &ans, string path, vector<vector<bool>> &visited, vector<vector<int >> &arr, int n ) {
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return ;
    }

    // now we have four movements i,e, Down, Left, Right, Up

    visited[x][y] = 1;

    // Down
    if (isSafe(x+1, y, arr, visited, n)) {
        solve(x+1, y, ans, path+'D', visited, arr, n);
    }

    // Left
    if (isSafe(x, y-1, arr, visited, n)) {
        solve(x, y-1, ans, path+'L', visited, arr, n);
    }

    // RIght
    if (isSafe(x, y+1, arr, visited, n)) {
        solve(x, y+1, ans, path+'R', visited, arr, n);
    }

    // Up
    if (isSafe(x-1, y, arr, visited, n)) {
        solve(x-1, y, ans, path+'U', visited, arr, n);
    }

    visited[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    if (arr[0][0] == 0) {
        return ans;
    }

    string path = "";
    vector<vector<bool>> visited(n, vector<bool> (n, 0));

    solve(0, 0, ans, path, visited, arr, n);

    return ans;
}