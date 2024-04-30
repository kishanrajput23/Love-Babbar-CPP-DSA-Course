/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findPosition(int in[],int startIndex,int element, int n){
        
        for(int i=startIndex; i<n; i++){
            if (in[i] == element){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int n, int &index, int inorderStart, int inorderEnd) {
        if ((index >= n) || (inorderStart > inorderEnd)) {
            return NULL;
        }
        
        int element = pre[index++];
        
        Node* root = new Node(element);
        
        int position = findPosition(in, inorderStart, element, n);
        
        root->left = solve(in, pre, n, index, inorderStart, position-1);
        root->right = solve(in, pre, n, index, position+1, inorderEnd);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code her
        int index  = 0;
        
        int inorderStart = 0;
        int inorderEnd = n-1;
        
        Node* ans = solve(in, pre, n, index, inorderStart, inorderEnd);
        return ans;
        
    }
};