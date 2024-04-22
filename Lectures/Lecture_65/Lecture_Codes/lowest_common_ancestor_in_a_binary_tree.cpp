/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        //Your code here 
        if (root == NULL) {
            return NULL;
        }
        
        if (root->data == n1 || root->data == n2) {
            return root;
        }
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if (leftAns != NULL && rightAns != NULL) {
            return root;
        }
        else if (leftAns != NULL && rightAns == NULL) {
            return leftAns;
        }
        else if (leftAns == NULL && rightAns != NULL) {
            return rightAns;
        }
        else {
            return NULL;
        }
    }
};