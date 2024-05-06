#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
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
    
};
***************/

void inorder(BinaryTreeNode<int>* root, vector<int> &v) {
    if (root == NULL) {
        return ;
    }

    inorder(root->left, v);

    v.push_back(root->data);

    inorder(root->right, v);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> v;
    inorder(root, v);

    int i=0;
    int j=v.size()-1;

    while (i<j) {
        int sum = v[i] + v[j];

        if (sum == target) {
            return true;
        }
        else if (sum > target) {
            j--;
        }
        else {
            i++;
        }
    }
    return false;
}