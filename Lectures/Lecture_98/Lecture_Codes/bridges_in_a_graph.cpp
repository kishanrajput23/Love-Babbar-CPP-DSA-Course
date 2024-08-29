#include<bits/stdc++.h>

using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, int &timer, vector<int> &low, 
            vector<int> &disc, int parent, unordered_map<int, bool> &vis, 
            vector<vector<int>> &result) {
    
    vis[node] = true;

    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue;
        }
        
        if (!vis[nbr]) {
            dfs(nbr, adj, timer, low, disc, node, vis, result);
            low[node] = min(low[node], low[nbr]);

            // check if edge is bridge or not
            if (low[nbr] > disc[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> low(v, -1);
    vector<int> disc(v, -1);
    int parent = -1;

    unordered_map<int, bool> vis;

    vector<vector<int>> result;

    for (int i=0; i<v; i++) {
        if (!vis[i]) {
            dfs(i, adj, timer, low, disc, parent, vis, result);
        }
    }

    return result;
}