#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void inorder(BinaryTreeNode<int> *root, vector<int> &v) {
    if (root == NULL) {
        return ;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<int> v;
    inorder(root, v);
    return is_sorted(v.begin(), v.end());
}