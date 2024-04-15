/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    
    pair<bool, int> isSumTreeFast(Node* root) {
        // base condtion
        if (root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        // neglecting leaf nodes
        if (root->left == NULL && root->right == NULL) {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        
        // checking whether left and right sub trees are sum tree
        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condtiton = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        
        if (isLeftSumTree && isRightSumTree && condtiton) {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum;
        }
        else {
            ans.first = false;
        }
        
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         return isSumTreeFast(root).first;
    }
};