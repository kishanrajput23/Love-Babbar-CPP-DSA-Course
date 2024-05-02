/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// TC = O(N);
// SC = O(1); 

class Solution{
  public:
  // inorder traversal
    void inorder(Node* root, Node* &successor, Node* x) {
        // base case
        if (root == NULL) {
            return ;
        }

        inorder(root->left, successor, x);
        
        if (root->data > x->data) {
            if (successor == NULL) {
                successor = root;
            }
        }
        
        inorder(root->right, successor, x);
    }
    
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* successor = NULL;
        inorder(root, successor, x);
        return successor;
    }
};