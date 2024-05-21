// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNodes(struct Node* tree) {
        if (tree == NULL) {
            return 0;
        }
        
        int left = countNodes(tree->left);
        int right = countNodes(tree->right);
        
        return 1 + left + right;
    }
    
    bool isCBT(struct Node* tree, int index, int n) {
        if (tree == NULL) {
            return true;
        }
        
        if (index >= n) {
            return false;
        }
        else {
            bool left = isCBT(tree->left, 2*index+1, n);
            bool right = isCBT(tree->right, 2*index+2, n);
            return left && right;
        }
    }
    
    bool isMaxHeap(struct Node* tree) {
        if (tree->left == NULL && tree->right == NULL) {
            return true;
        }
        
        if (tree->right == NULL) {
            return tree->data > tree->left->data; 
        }
        else {
            bool left = isMaxHeap(tree->left);
            bool right = isMaxHeap(tree->right);
            bool ans = tree->data > tree->left->data && tree->data > tree->right->data;
            
            return left && right && ans;
        }
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int n = countNodes(tree);
        
        if (isCBT(tree, index, n) && isMaxHeap(tree)) {
            return true;
        }
        return false;
    }
};