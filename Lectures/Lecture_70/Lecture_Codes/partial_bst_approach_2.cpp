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

bool inorder(BinaryTreeNode<int> *root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if (root->data >= min && root->data <= max) {
        bool left = inorder(root->left, min, root->data);
        bool right = inorder(root->right, root->data, max);
        return left && right;
    }

    return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return inorder(root, INT_MIN, INT_MAX);
    
}