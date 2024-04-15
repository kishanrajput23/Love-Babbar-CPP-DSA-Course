#include<iostream>
#include<queue>

using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = left;
        this->right = right;
    }
};


// creating a tree
node* buildTree(node* root) {
    cout<<"Enter the data : ";
    int data;
    cin>>data;

    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    cout<<"Enter the data for inserting in left of "<<data<< endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

// level order traversal

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);       // used as separator so that we can recognise where our level is ending

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // that means our previous level is completed and we'll print new line
            cout<<endl;

            if (!q.empty()) {
                // that means queue has still some child node left
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data<<" ";
            
            if (temp->left != NULL) {
                q.push(temp->left);
            }

            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
    }
}


// inorder traversal
void inorder(node* root) {
    // base case
    if (root == NULL) {
        return ;
    }

    inorder(root->left);        // L
    cout<<root->data<<" ";      // N
    inorder(root->right);       // R
}

// preorder traversal
void preorder(node* root) {
    // base case
    if (root == NULL) {
        return ;
    }

    cout<<root->data<<" ";       // N
    preorder(root->left);        // L
    preorder(root->right);       // R
}

// postorder traversal
void postorder(node* root) {
    // base case
    if (root == NULL) {
        return ;
    }

    postorder(root->left);         // L
    postorder(root->right);        // R
    cout<<root->data<<" ";         // N
}

// building tree from level order traversal
void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout<<"Enter the data : ";
    int data;
    cin>>data;

    root = new node(data);
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {

    node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1       copy paste this to build tree in one go else mannually enter one by one
    // creating a binary tree
    root = buildTree(root);

    // level order traversal
    cout<<"Printing the level order traversal output"<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder Traversal : ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder Traversal : ";
    postorder(root);
    cout<<endl;
    

    // building tree from level order traversal
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    return 0;
}