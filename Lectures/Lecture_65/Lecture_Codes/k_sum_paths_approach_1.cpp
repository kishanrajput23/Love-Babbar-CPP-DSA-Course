//User function template for C++

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

// Gives TLE

class Solution{
    public:
    void dfs(Node* root, int k, int &count, vector<int> path) {
        if (root == NULL) {
            return ;
        }
        
        path.push_back(root->data);
        
        dfs(root->left, k, count, path);
        dfs(root->right, k, count, path);
        
        int sum = 0;
        for (int i=path.size()-1; i>=0; i--) {
            sum += path[i];
            
            if (sum == k) {
                count++;
            }
        }
        
        path.pop_back();
    }
    
    int sumK(Node *root,int k) {
        // code here 
        int count = 0;
        vector<int> path;
        dfs(root, k, count, path);
        return count;
    }
};