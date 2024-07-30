#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // visited map to track the nodes
    unordered_map<int, bool> visited;

    // parent map to track parent of each node
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                parent[i] = node;
                q.push(i);
            }
        }
    }
    
    // getting shortest path from parent map
    vector<int> ansPath;
    int currNode = t;
	ansPath.push_back(t);

    while (currNode != s) {
        currNode = parent[currNode];
        ansPath.push_back(currNode);
    }

    // reversing the ans vectore as we backtrack path from destination to source
    reverse(ansPath.begin(), ansPath.end());

    return ansPath;
}
