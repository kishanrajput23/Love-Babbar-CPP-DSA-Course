/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    void traverseLeft(Node* root, vector<int> &v) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return ;
        }
        
        v.push_back(root->data);
        
        if(root->left != NULL) {
            traverseLeft(root->left, v);
        }
        else {
            traverseLeft(root->right, v);
        }
    }
    
    void traverseLeaf(Node* root, vector<int> &v) {
        if (root == NULL) {
            return ;
        }
        
        if (root->left == NULL && root->right == NULL) {
            v.push_back(root->data);
            return ;
        }
        
        traverseLeaf(root->left, v);
        traverseLeaf(root->right, v);
    }
    
    void traverseRight(Node* root, vector<int> &v) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return ;
        }
        
        if(root->right != NULL) {
            traverseRight(root->right, v);
        }
        else {
            traverseRight(root->left, v);
        }
        
        v.push_back(root->data);
    }
    
    vector <int> boundary(Node *root) {
        //Your code here
        vector<int> v;
        
        if (root == NULL) {
            return v;
        }
        
        v.push_back(root->data);
        
        // traverse left
        traverseLeft(root->left, v);
        
        // traverse left leaf nodes
        traverseLeaf(root->left, v);
        
        // traverse right leaf nodes
        traverseLeaf(root->right, v);
        
        // traverse right
        traverseRight(root->right, v);
        
        return v;
    }
};