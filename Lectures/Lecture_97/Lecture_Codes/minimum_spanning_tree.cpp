#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort edges by their weight
bool comp(vector<int> &a, vector<int> &b) {
  return a[2] < b[2];
}

// Initializes the disjoint set data structure
void makeSet(vector<int> &parent, vector<int> &rank, int n) {
  for (int i = 0; i < n; i++) {
    parent[i] = i;  // Each node is its own parent initially
    rank[i] = 0;    // Rank of each node is 0 initially
  }
}

// Finds the representative (root) of the set containing 'node'
// Uses path compression to flatten the structure for efficiency
int findParent(vector<int> &parent, int node) {
  if (parent[node] == node) {
    return node;  // If node is its own parent, return it
  }

  // Path compression: make the parent of the node point directly to the root
  return parent[node] = findParent(parent, parent[node]);
}

// Unites two subsets into a single subset using union by rank
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
  u = findParent(parent, u);  // Find root of the set containing 'u'
  v = findParent(parent, v);  // Find root of the set containing 'v'

  if (rank[u] < rank[v]) {
    parent[u] = v;  // Attach the tree with smaller rank under the larger rank
  }
  else if (rank[v] < rank[u]) {
    parent[v] = u;  // Attach the tree with smaller rank under the larger rank
  }
  else {
    parent[v] = u;  // If ranks are equal, choose one as the new root
    rank[u]++;      // Increase the rank of the new root
  }
}

// Computes the weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm
int minimumSpanningTree(vector<vector<int>>& edges, int n) {
  // Sort edges based on their weights in non-decreasing order
  sort(edges.begin(), edges.end(), comp);

  vector<int> parent(n);
  vector<int> rank(n);

  // Initialize the disjoint set
  makeSet(parent, rank, n);

  int minWeight = 0;  // To keep track of the total weight of the MST

  // Iterate over all edges and add to MST if they don't form a cycle
  for (int i = 0; i < edges.size(); i++) {
    int u = findParent(parent, edges[i][0]);  // Find root of the first vertex of the edge
    int v = findParent(parent, edges[i][1]);  // Find root of the second vertex of the edge
    int w = edges[i][2];  // Weight of the edge

    // If the vertices are in different sets, add the edge to the MST
    if (u != v) {
      minWeight += w;  // Add the weight of the edge to the total weight of the MST
      unionSet(u, v, parent, rank);  // Union the sets of the two vertices
    }
  }

  return minWeight;  // Return the total weight of the MST
}
