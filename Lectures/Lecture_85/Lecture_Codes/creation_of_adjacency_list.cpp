#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

/*
--> addAdj Function:

Time Complexity: O(1) on average case for adding an edge. This is because unordered_map provides constant-time average insertion.

Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges. This is because each vertex is stored as a key in the unordered_map, and for each vertex, its adjacency list stores all its adjacent vertices.

--> displayAdjList Function:

Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges. This is because we iterate through all vertices and for each vertex, we iterate through its adjacency list once.

Space Complexity: O(V + E), same as the space complexity of the adjacency list itself because we're just printing the adjacency list without modifying it.
*/

class Graph {
    public:

    unordered_map<int, list<int> > adj;

    void addAdj(int u, int v, bool direction) {
        adj[u].push_back(v);

        // direction : 0 --> (undirected graph)
        // direction : 1 --> (directed graoh)

        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void diplayAdjList() {
        for (auto i : adj) {
            cout<<i.first<<" --> ";
            for (auto j : i.second) {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes : ";
    cin>>n;

    int m;
    cout<<"Enter the number of edges : ";
    cin>>m;

    Graph g;

    for (int i=0; i<m; i++) {
        int u, v;
        cout<<"Enter the edge : ";
        cin>>u>>v;

        g.addAdj(u, v, 0);
    }

    g.diplayAdjList();

    return 0;
}