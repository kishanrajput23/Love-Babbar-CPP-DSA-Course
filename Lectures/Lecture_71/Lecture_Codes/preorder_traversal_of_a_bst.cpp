#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i) {
    if (i >= preorder.size()) {
        return NULL;
    }

    if (preorder[i] < mini || preorder[i] > maxi) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i=0;
    return solve(preorder, mini, maxi, i);
}