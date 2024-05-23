#include <bits/stdc++.h> 

class Node {
    public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class Compare {
    public:
    bool operator() (Node* a, Node* b) {
        return a->data > b->data;
    }
};

// TC = O(nklog(k))
// SC = O(nk)

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    // Write your code here. 
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i=0; i<k; i++) {
        Node* temp = new Node(kArrays[i][0], i, 0);
        pq.push(temp);
    }

    vector<int> ans;

    while (!pq.empty()) {
        Node* temp = pq.top();
        pq.pop();

        ans.push_back(temp->data);

        int newRow = temp->row;
        int newCol = temp->col;

        if (newCol + 1 < kArrays[newRow].size()) {
            Node* next = new Node(kArrays[newRow][newCol+1], newRow, newCol+1);
            pq.push(next);
        }
    }
    return ans;
}
