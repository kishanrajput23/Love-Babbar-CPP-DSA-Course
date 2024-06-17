#include<bits/stdc++.h>

// using bfs

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // adjacency list
  unordered_map<int, list<int>> adj;

  for (int i=0; i<edges.size(); i++) {
    // doing -1 because our vertices start from 1
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;
    adj[u].push_back(v);
  }

  // finding indgrees of vertices
  vector<int> indegree(n);
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

  int count = 0;

  while (!q.empty()) {
    int front = q.front();
    q.pop();

    // increment count
    count++;

    for (auto neighbour : adj[front]) {
      indegree[neighbour]--;

      if (indegree[neighbour] == 0) {
        q.push(neighbour);
      }
    }
  }

  if (count == n) {
    return false;
  }

  return true;
}