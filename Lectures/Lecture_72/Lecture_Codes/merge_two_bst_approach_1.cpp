/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void inorder(TreeNode* root, vector<int> &v) {
    if (root == NULL) {
        return ;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> v1;
    inorder(root1, v1);

    vector<int> v2;
    inorder(root2, v2);

    // vector<int> v = v1+v2;
    v1.insert(v1.end(), v2.begin(), v2.end());

    sort(v1.begin(), v1.end());

    return v1;
}