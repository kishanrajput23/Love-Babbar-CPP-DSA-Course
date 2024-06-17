#include <bits/stdc++.h> 

// using bfs

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // adjacency list
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // finding indgrees of vertices
    vector<int> indegree(v);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;
    
    // pushing vertices having 0 indegree
    for (int i=0; i<indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}