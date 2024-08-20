// TC = O(N^2)

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creating adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i=0; i<g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    key[1] = 0;
    parent[1] = -1;

    // step 1 : find minimum node from key vector
    for (int i=1; i<n; i++) {
        int mini = INT_MAX;
        int u;

        for (int j=0; j<=n; j++) {
            if (mst[j] == false && key[j] < mini) {
                u = j;
                mini = key[j];
            }
        }

        // step 2 : mark mst as true for minimum node;
        mst[u] = true;

        // step 3 : check adjacent nodes of minimum node
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i=2; i<=n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;

}
