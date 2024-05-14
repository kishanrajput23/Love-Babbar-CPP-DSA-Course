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

vector<int> mergeArray(vector<int> v1, vector<int> v2) {
    vector<int> v(v1.size() + v2.size());
    int i=0, j=0, k=0;

    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            v[k++] = v1[i++];
        }
        else {
            v[k++] = v2[j++];
        }
    }

    while (i < v1.size()) {
        v[k++] = v1[i++];
    }

    while (j < v2.size()) {
        v[k++] = v2[j++];
    }

    return v;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> v1;
    inorder(root1, v1);

    vector<int> v2;
    inorder(root2, v2);

    return mergeArray(v1, v2);
}