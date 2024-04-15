#include<iostream>
#include<queue>
#include<stack>

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

// reverse level order traversal
void reverseLevelOrderTraversal(node* root) {
    queue<node*> q;
    stack<int> st;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        st.push(temp->data);

        if (temp->right != NULL) {
            q.push(temp->right);
        }

        if (temp->left != NULL) {
            q.push(temp->left);
        }
    }

    while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main() {

    node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1       copy paste this to build tree in one go else mannually enter one by one
    // creating a binary tree
    root = buildTree(root);

    // level order traversal
    cout<<"Printing the level order traversal output"<<endl;
    levelOrderTraversal(root);

    // reverse level order traversal
    cout<<"Printing the reverse level order traversal output"<<endl;
    reverseLevelOrderTraversal(root);

}