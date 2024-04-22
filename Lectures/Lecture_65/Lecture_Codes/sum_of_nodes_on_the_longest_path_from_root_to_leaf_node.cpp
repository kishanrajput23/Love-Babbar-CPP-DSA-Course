/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:

    void solve(Node* root, int len, int &maxLen, int sum, int &maxSum) {
        if (root == NULL) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
            return ;
        }
        
        sum += root->data;
        
        solve(root->left, len+1, maxLen, sum, maxSum);
        solve(root->right, len+1, maxLen, sum, maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len = 0;
        int maxLen = 0;
        int maxSum = 0;
        int sum = 0;
        
        solve(root, len, maxLen, sum, maxSum);
        return maxSum;
    }
};