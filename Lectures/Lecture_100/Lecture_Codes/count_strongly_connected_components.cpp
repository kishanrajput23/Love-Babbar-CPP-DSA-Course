#include<bits/stdc++.h>

void dfs(int node, stack<int> &st, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
	visited[node] = true;

	for (auto nbr : adj[node]) {
		if (!visited[nbr]) {
			dfs(nbr, st, visited, adj);
		}
	}

	st.push(node);
}

void revDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &transpose) {
	visited[node] = true;

	for (auto nbr : transpose[node]) {
		if (!visited[nbr]) {
			revDFS(nbr, visited, transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
	// creating adjacency list

	unordered_map<int, list<int>> adj;

	for (int i=0; i<edges.size(); i++) {
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	// topological sort
	stack<int> st;
	unordered_map<int, bool> visited;

	for (int i=0; i<v; i++) {
		if (!visited[i]) {
			dfs(i, st, visited, adj);
		}
	}

	// creating a transpose graph
	unordered_map<int, list<int>> transpose;
	for (int i=0; i<v; i++) {
		visited[i] = false;
		for (auto nbr : adj[i]) {
			transpose[nbr].push_back(i);
		}
	}

	// dfs call using above ordering i,e, transpose
	int count = 0;

	while (!st.empty()) {
		int top = st.top();
		st.pop();

		if (!visited[top]) {
			count++;
			revDFS(top, visited, transpose);
		}
	}

	return count;
}