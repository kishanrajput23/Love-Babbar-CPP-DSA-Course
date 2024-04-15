/* A binary tree Node

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
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root) {
      //Your code here
        queue<Node*> q;
        q.push(root);
        
        vector<int> v;
        Node* temp;
        
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            
            v.push_back(temp->data);
            
            if (temp->left != NULL) {
                q.push(temp->left);
            }

            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        return v;
    }
};