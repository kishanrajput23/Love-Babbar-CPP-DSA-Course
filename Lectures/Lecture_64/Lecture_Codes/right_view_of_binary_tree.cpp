/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    void traverse(Node* root, vector<int> &v, int level) {
    if (root == NULL) {
        return;
    }
    
    if (v.size() == level) {
        v.push_back(root->data);
    }
    
    traverse(root->right, v, level+1);
    traverse(root->left, v, level+1);
    
}

    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> v;
        int level = 0;
        traverse(root, v, level);
        return v;
    }
};