//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
void solve(Node* root, int &node, vector<int> &v, bool &found) {
    if (root == NULL) {
        return ;
    }
    
    if (root->data == node) {
        found = 1;
        return ;
    }
    
    solve(root->left, node, v, found);
    
    if (found) {
        v.push_back(root->data);
        return ;
    }
    
    solve(root->right, node, v, found);
    
    if (found) {
        v.push_back(root->data);
        return ;
    }
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    bool found = 0;
    
    vector<int> v;
    
    solve(root, node, v, found);
    
    if (v.size() < k) {
        return -1;
    }
    return v[k-1];
}