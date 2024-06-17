#include <bits/stdc++.h> 

void topoSort(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj) {
    visited[node] = 1;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, st, adj);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // adjacency list
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> st;

    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }

    vector<int> ans;

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}