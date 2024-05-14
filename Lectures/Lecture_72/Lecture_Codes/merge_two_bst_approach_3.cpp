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

void convertToDLL(TreeNode* root, TreeNode* &head) {
    if (root == NULL) {
        return ;
    }

    convertToDLL(root->right, head);

    root->right = head;

    if (head != NULL) {
        head->left = root;
    }

    head = root;

    convertToDLL(root->left, head);
}

TreeNode* mergeLists(TreeNode* head1, TreeNode* head2) {
    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }

    if (head1 ==NULL && head2 == NULL) {
        return NULL;
    }

    TreeNode* ans = new TreeNode(-1);
    TreeNode* temp = ans;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            temp->right = head1;
            temp = head1;
            head1 = head1->right;
        }
        else {
            temp->right = head2;
            temp = head2;
            head2 = head2->right;
        }
    }

    while (head1 != NULL) {
        temp->right = head1;
        temp = head1;
        head1 = head1->right;
    }
        
    while (head2 != NULL) {
        temp->right = head2;
        temp = head2;
        head2 = head2->right;
    }
        
    return ans->right;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    TreeNode* head1 = NULL;
    TreeNode* head2 = NULL;

    convertToDLL(root1, head1);
    convertToDLL(root2, head2);

    TreeNode* result = mergeLists(head1, head2);

    TreeNode* temp = result;
    vector<int> v;

    while (temp != NULL) {
        v.push_back(temp->data);
        temp = temp->right;
    }
       
    return v;
}