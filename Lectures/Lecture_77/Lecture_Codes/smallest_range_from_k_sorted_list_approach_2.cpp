#include<bits/stdc++.h>

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

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    priority_queue<Node*, vector<Node*>, Compare> pq;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int range = INT_MAX;

    for (int i=0; i<k; i++) {
        Node* temp = new Node(a[i][0], i, 0);
        pq.push(temp);

        int val = a[i][0];
        mini = min(mini, val);
        maxi = max(maxi, val);
    }

    int start = mini;
    int end = maxi;

    while (!pq.empty()) {
        Node* temp = pq.top();
        pq.pop();

        mini = temp->data;

        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        if (temp->col + 1 < n) {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            pq.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else {
            break;
        }
    }

    return end - start + 1;
}