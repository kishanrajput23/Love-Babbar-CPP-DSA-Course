#include<bits/stdc++.h>

// TC = O(nk^2);
// SC = O(k);

class Node {
    public:
    int data;
    int row;
    int index;

    Node(int data, int row, int index) {
        this->data = data;
        this->row = row;
        this->index = index;
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

    while (!pq.empty()) {
        Node* temp = pq.top();
        pq.pop();

        int mayBeMinimum = temp->data;
        if (range > maxi - mayBeMinimum) {
            mini = mayBeMinimum;
            range = maxi - mini;
        }

        if (temp->index >= n-1) {
            break;
        }

        temp->index += 1;

        Node* node = new Node(a[temp->row][temp->index], temp->row, temp->index);
        pq.push(node);

        maxi = max(maxi, a[temp->row][temp->index]);
    }

    return range+1;
}