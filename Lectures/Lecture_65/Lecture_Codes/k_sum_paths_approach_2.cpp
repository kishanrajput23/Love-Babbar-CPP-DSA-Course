/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    int count = 0;
    const int mod = 1e9+7;
    void solve(Node* root, int k, int sum, unordered_map<int, int> &mp) {
        if (root == NULL) {
            return ;
        }
        
        sum += root->data;
        
        count = (count + mp[sum-k]) % mod;
        mp[sum]++;
        
        solve(root->left, k, sum, mp);
        solve(root->right, k, sum, mp);
        
        mp[sum]--;
    }
    
    int sumK(Node *root,int k) {
        // code here 
        unordered_map<int, int> mp;
        mp[0] = 1;
        solve(root, k, 0, mp);
        return count;
    }
};
