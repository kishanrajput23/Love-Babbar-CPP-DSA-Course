#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
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
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root, vector<int> &v) {
    if (root == NULL) {
        return ;
    }

    inorder(root->left, v);

    v.push_back(root->data);

    inorder(root->right, v);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> v;
    inorder(root, v);

    TreeNode<int>* newRoot = new TreeNode<int>(v[0]);

    TreeNode<int>* curr = newRoot;

    for (int i=1; i<v.size();  i++) {
        TreeNode<int>* temp = new TreeNode<int>(v[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;
    
    return newRoot;
}
