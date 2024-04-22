//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    pair<int, int> solve(Node* root) {
        if (root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);
        
        pair<int, int> res;
        
        res.first = root->data + leftAns.second + rightAns.second;
        
        res.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        
        return res;
    }
    
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)  {
        // Add your code here
        pair<int, int> ans = solve(root);
        
        // ans.first = holds the maxSum by including nodes of current level
        // ans.second = hold the maxSum by excluding nodes of current level
        
        return max(ans.first, ans.second);
    }
};