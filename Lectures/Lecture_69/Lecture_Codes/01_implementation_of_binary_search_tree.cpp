#include<iostream>
#include<queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node* root, int data) {
    // base case
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root->data) {
        // inserting in right side of the root
        root->right = insertToBST(root->right, data);
    }
    else {
        // inserting in left side of the root
        root->left = insertToBST(root->left, data);
    }
    
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin>>data;

    while (data != -1) {
        root = insertToBST(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);       // used as separator so that we can recognise where our level is ending

    while (!q.empty()) {
        Node* temp = q.front();
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
void inorder(Node* root) {
    // base case
    if (root == NULL) {
        return ;
    }

    inorder(root->left);        // L
    cout<<root->data<<" ";      // N
    inorder(root->right);       // R
}

// preorder traversal
void preorder(Node* root) {
    // base case
    if (root == NULL) {
        return ;
    }

    cout<<root->data<<" ";       // N
    preorder(root->left);        // L
    preorder(root->right);       // R
}

// postorder traversal
void postorder(Node* root) {
    // base case
    if (root == NULL) {
        return ;
    }

    postorder(root->left);         // L
    postorder(root->right);        // R
    cout<<root->data<<" ";         // N
}

Node* minVal(Node* root) {
    Node* temp = root;

    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;

    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (root->data == val) {
        // if 0 child exists
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // if only 1 child exists
            // case 1 : for left child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

            // case 2 : for right child
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // if 2 child exits
        if (root->left != NULL && root->right != NULL) {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main() {

    Node* root = NULL;

    cout<<"Enter the data to create BST : "<<endl;
    takeInput(root);

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

    cout<<"Min value in BST is : "<<minVal(root)->data<<endl;
    cout<<"Max value in BST is : "<<maxVal(root)->data<<endl;

    deleteFromBST(root, 30);

    // verifying after deleting node value
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

    cout<<"Min value in BST is : "<<minVal(root)->data<<endl;
    cout<<"Max value in BST is : "<<maxVal(root)->data<<endl;

    return 0;
}