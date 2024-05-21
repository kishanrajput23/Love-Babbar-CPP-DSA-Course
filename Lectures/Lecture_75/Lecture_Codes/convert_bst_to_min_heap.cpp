// C++ implementation to convert the given
// BST to Min Heap

#include <bits/stdc++.h>
using namespace std;

// Structure of a node of BST
struct Node {

	int data;
	Node *left, *right;
};


struct Node* getNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void inorderTraversal(Node* root, vector<int>& arr) {
	if (root == NULL)
		return;

	inorderTraversal(root->left, arr);
	arr.push_back(root->data);
	inorderTraversal(root->right, arr);
}

// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> arr, int &i) {
	if (root == NULL)
		return;

	// first copy data at index 'i' of 'arr' to the node
	root->data = arr[i++];

	// then recur on left subtree
	BSTToMinHeap(root->left, arr, i);

	// now recur on right subtree
	BSTToMinHeap(root->right, arr, i);
}

// utility function to convert the given BST to MIN HEAP
void convertToMinHeapUtil(Node* root) {
	// vector to store the data of all the nodes of the BST
	vector<int> arr;
	int i = 0;

	// inorder traversal to populate 'arr'
	inorderTraversal(root, arr);

	// BST to MIN HEAP conversion
	BSTToMinHeap(root, arr, i);
}

// function for the preorder traversal of the tree
void preorderTraversal(Node* root) {
	if (!root)
		return;

	// first print the root's data
	cout << root->data << " ";

	// then recur on left subtree
	preorderTraversal(root->left);

	// now recur on right subtree
	preorderTraversal(root->right);
}

// Driver program to test above
int main() {
	// BST formation
	struct Node* root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(6);
	root->left->left = getNode(1);
	root->left->right = getNode(3);
	root->right->left = getNode(5);
	root->right->right = getNode(7);

	// Function call
	convertToMinHeapUtil(root);
	
	cout << "Preorder Traversal:" << endl;
	preorderTraversal(root);

	return 0;
}
