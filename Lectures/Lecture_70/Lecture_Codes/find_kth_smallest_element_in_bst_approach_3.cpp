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
// using morris traversal

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    // Count until get the kth smallest number
	int count = 0;

	// To store kth smallest element
	int ksmall = -1;

	// Node to store the current node
	BinaryTreeNode<int>* curr = root; 
	
	while (curr != NULL)
	{
		// If the left child is null, increment count.
		if (curr->left == NULL)
		{
			count++;
			
			// Check if count becomes equal to K
			if (count==k)
			ksmall = curr->data;

			// Set current to the right child 
			curr = curr->right;
		}
		else
		{
			// If the current is not null, add a link to inorder successor 
			BinaryTreeNode<int>* prev = curr->left;
			while (prev->right != NULL && prev->right != curr)
			prev = prev->right;

			if (prev->right==NULL)
			{
				// link right to inorder sccessor
				prev->right = curr;
				curr = curr->left;
			}
			else
			{
				prev->right = NULL;
				count++;
     	       
     	         // Check if count becomes equal to K
                if (count==k)
  			  
  			    ksmall = curr->data;
 			    // Check for the right subtree
			    curr = curr->right;
			}
		}
	}
	// Return Kth smallest element 
	return ksmall; 
}