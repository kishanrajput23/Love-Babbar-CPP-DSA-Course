/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inorder(TreeNode<int>* root, vector<int> &v) {
    if (root == NULL) {
        return ;
    }

    inorder(root->left, v);

    v.push_back(root->data);

    inorder(root->right, v);
}

TreeNode<int>* inorderToBST(int start, int end, vector<int> v) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;

    TreeNode<int>* newRoot = new TreeNode<int>(v[mid]);
    
    newRoot->left = inorderToBST(start, mid-1, v);
    newRoot->right = inorderToBST(mid+1, end, v);

    return newRoot;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> v;
    inorder(root, v);

    return inorderToBST(0, v.size()-1, v);
}
