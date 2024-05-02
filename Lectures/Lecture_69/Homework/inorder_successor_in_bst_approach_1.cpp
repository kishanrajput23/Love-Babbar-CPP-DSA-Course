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
// SC = O(N); 

class Solution{
  public:
  // inorder traversal
    void inorder(Node* root, vector<int> &v) {
        // base case
        if (root == NULL) {
            return ;
        }

        inorder(root->left, v);        // L
        v.push_back(root->data);      // N
        inorder(root->right, v);       // R
    }
    
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* successor = NULL;
        vector<int> v;
        inorder(root, v);
        
        for (int i=0; i<v.size(); i++) {
            if (v[i] == x->data && (i+1 < v.size())) {
                successor = new Node(v[i+1]);
                break;
            }
        }
        return successor;
    }
};