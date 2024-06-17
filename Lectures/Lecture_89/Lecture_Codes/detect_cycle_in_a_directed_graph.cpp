#include<bits/stdc++.h>

bool isCyclicDFS(int node, unordered_map<int, int> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj) {
  visited[node] = 1;
  dfsVisited[node] = 1;

  for (auto neighbour : adj[node]) {
    if (!visited[neighbour]) {
      bool cycleDetected = isCyclicDFS(neighbour, visited, dfsVisited, adj);

      if (cycleDetected) {
        return true;
      }
    }
    else if (dfsVisited[neighbour] == 1) {
      return true;
    }
  }

  dfsVisited[node] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int, list<int>> adj;

  // adjacency list
  for (int i=0; i<edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int, int> visited;
  unordered_map<int, bool> dfsVisited;

  for (int i=1; i<=n; i++) {
    if (!visited[i]) {
      bool ans = isCyclicDFS(i, visited, dfsVisited, adj);

      if (ans == 1) {
        return true;
      }
    }
  }
  return false;
}