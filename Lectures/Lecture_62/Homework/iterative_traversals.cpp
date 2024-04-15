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


void inorder(node* root) {
    if (root == NULL) {
        return ;
    }

    stack<node*> st;
    while (true) {
        if (root != NULL) {
            st.push(root);
            root = root->left;
        }
        else {
            if (st.empty()) {
                break;
            }
            root = st.top();
            st.pop();
            cout<<root->data<<" ";
            root = root->right;
        }
    }
}

void preorder(node* root) {
    if (root == NULL) {
        return ;
    }

    stack<node*> st;
    st.push(root);

    while (!st.empty()) {
        root = st.top();
        cout<<root->data<<" ";
        st.pop();

        if (root->right != NULL) {
            st.push(root->right);
        }

        if (root->left != NULL) {
            st.push(root->left);
        }
    }
}

void postorder(node* root) {
    if (root == NULL) {
        return ;
    }

    stack<node*> st;
    node* curr = root;
    while (!st.empty() || curr != NULL) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            node* temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                st.pop();
                cout<<temp->data<<" ";

                while (!st.empty() && temp == st.top()->right) {
                    cout<<st.top()->data<<" ";
                    st.pop();
                }
            }
            else {
                curr = temp;
            }
        }
    }
}

int main() {

    node* root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1       copy paste this to build tree in one go else mannually enter one by one
    // creating a binary tree
    root = buildTree(root);

    cout<<"Inorder Traversal : ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder Traversal : ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder Traversal : ";
    postorder(root);
    cout<<endl;

}