#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>

using namespace std;

class Graph {
    public:
    // Adjacency list representation of the graph
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);  // Add an edge from u to v with the given weight
    }

    // Function to print the adjacency list of the graph
    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";  // Print the current node
            for (auto j : i.second) {
                cout << "(" << j.first << ", " << j.second << "), ";  // Print each neighbor and its weight
            }
            cout << endl;
        }
    }

    // Depth-First Search (DFS) to perform topological sorting
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st) {
        visited[node] = true;  // Mark the current node as visited

        // Recur for all the neighbors of the current node
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour.first]) {
                dfs(neighbour.first, visited, st);  // Recursive call for unvisited neighbors
            }
        }

        st.push(node);  // Push the current node to the stack after visiting all its neighbors
    }

    // Function to get the shortest path from the source node using the distances
    void getShortestPath(int src, vector<int> &dist, stack<int> &st) {
        dist[src] = 0;  // Distance to the source node is 0

        // Process nodes in topologically sorted order
        while (!st.empty()) {
            int node = st.top();  // Get the top node from the stack
            st.pop();  // Remove the node from the stack

            // Update the distance for each neighbor of the current node
            if (dist[node] != INT_MAX) {
                for (auto i : adj[node]) {
                    if (dist[node] + i.second < dist[i.first]) {
                        dist[i.first] = dist[node] + i.second;  // Relax the edge
                    }
                }
            }
        }
    }
};

int main() {

    Graph g;

    // Adding edges to the graph
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // Printing the adjacency list to see the graph structure
    g.printAdjList();

    // Topological sort initialization
    int n = 6;       // Number of nodes in the graph
    unordered_map<int, bool> visited;
    stack<int> st;

    // Perform DFS for each node to get the topological order
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.dfs(i, visited, st);
        }
    }

    int src = 1;        // Source node for shortest path calculation
    vector<int> dist(n, INT_MAX);  // Initialize distances with infinity
    g.getShortestPath(src, dist, st);  // Compute shortest paths from the source node

    // Print the shortest path distances
    cout << "The shortest path is : ";
    for (auto i : dist) {
        cout << i << " ";  // Print distance of each node from the source
    }
    cout << endl;

    return 0;
}
