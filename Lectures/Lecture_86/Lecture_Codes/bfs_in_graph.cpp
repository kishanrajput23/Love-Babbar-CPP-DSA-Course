#include<bits/stdc++.h>

// TC = O(N+E)
// SC = O(N+E);

void bfs(vector<vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int node) {
    queue<int> q;

    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // store front node to ans vector
        ans.push_back(front);

        // adding all neighbours into queue;
        for (auto i : adj[front]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    unordered_map<int, bool> visited;
    vector<int> ans;

    //given that the breadth first traversal is starting form 0
    bfs(adj, ans, visited, 0); 

    return ans;
}