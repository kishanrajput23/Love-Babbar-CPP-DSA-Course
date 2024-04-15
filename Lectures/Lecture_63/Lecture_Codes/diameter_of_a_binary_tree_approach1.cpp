/* Tree node structure  used in the program

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

class Solution {
  public:
    int height(struct Node* node){  
        // code here 
        if (node == NULL) {
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        
        return ans;
    }
    
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if (root == NULL) {
            return 0;
        }
        
        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        
        int diff = height(root->left) + height(root->right) + 1;
        
        int ans = max(op1, max(op2, diff));
        return ans;
    }
};