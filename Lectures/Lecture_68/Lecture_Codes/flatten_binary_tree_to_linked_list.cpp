// by using morris traversal
class Solution{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr = root;
        
        while (curr != NULL) {
            if (curr->left != NULL) {
                Node* pred = curr->left;
                
                while(pred->right != NULL) {
                    pred = pred->right;
                }
                
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;      // if we forget to add this line then we can use below code
            }
            curr = curr->right;
        }
        
        // left part NULL
        // curr = root;
        // while (curr != NULL) {
        //     curr->left = NULL;
        //     curr = curr->right;
        // }
    }
};