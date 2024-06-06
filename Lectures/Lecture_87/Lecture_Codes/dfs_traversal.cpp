void prepareAdjList(vector<vector<int>> &edges, unordered_map<int, list<int> > &adjList) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>> &adjList, vector<int> &component,
         unordered_map<int, bool> &visited, int node) {
    component.push_back(node);
    visited[node] = 1;

    // recursive call for every connected node
    for (auto i : adjList[node]) {
        if (!visited[i]) {
            dfs(adjList, component, visited, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Write your code here
    unordered_map<int, list<int> > adjList; 
    unordered_map<int, bool> visited; 
    vector<vector<int> > ans;

    // making adjacency list
    prepareAdjList(edges, adjList);

    // traversing the all components of a graph
    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(adjList, component, visited, i);
            ans.push_back(component);
        }
    }    

    return ans;
}