/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.

    BinaryTreeNode<int> *temp = root;

    while (temp != NULL) {
        if (temp->data == x) {
            return true;
        }

        if (temp->data < x) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    return false;
}