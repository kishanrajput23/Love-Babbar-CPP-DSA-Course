/*
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
    void createMapping(int in[], map<int, int> &mp, int n) {
        for (int i=0; i<n; i++) {
            mp[in[i]] = i;
        }
    }
    
    Node* solve(int in[], int post[], int n, int &index, map<int, int> &mp, int inorderStart, int inorderEnd) {
        if ((index < 0) || (inorderStart > inorderEnd)) {
            return NULL;
        }
        
        int element = post[index--];
        
        Node* root = new Node(element);
        
        int position = mp[element];
        
        root->right = solve(in, post, n, index, mp, position+1, inorderEnd);
        root->left = solve(in, post, n, index, mp, inorderStart, position-1);
        
        return root;
    }

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        map<int, int> mp;
        createMapping(in, mp, n);
        
        int index  = n-1;
        
        int inorderStart = 0;
        int inorderEnd = n-1;
        
        Node* ans = solve(in, post, n, index, mp, inorderStart, inorderEnd);
        return ans;
    }
};