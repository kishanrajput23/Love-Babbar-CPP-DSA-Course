/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // function to create mapping of each node to its parent node
    Node* createMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
        
        Node* res = NULL;
        
        queue<Node*> q;
        q.push(root);
        
        nodeToParent[root] = NULL;
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if (front->data == target) {
                res = front;
            }
            
            if (front->left != NULL) {
                q.push(front->left);
                nodeToParent[front->left] = front;
            }
            
            if (front->right != NULL) {
                q.push(front->right);
                nodeToParent[front->right] = front;
            }
        }
        
        return res;
    }
    
    // function to find min time to burn a tree
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
        int time = 0;
        
        map<Node*, bool> visited;
        
        queue<Node*> q;
        q.push(root);
        
        visited[root] = true;
        
        while(!q.empty()) {
            int n = q.size();
            bool flag = 0;
            
            for (int i=0; i<n; i++) {
                Node* front = q.front();
                q.pop();
                
                if (front->left != NULL && !visited[front->left]) {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                
                if (front->right != NULL && !visited[front->right]) {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                
                if (nodeToParent[front] != NULL && !visited[nodeToParent[front]]) {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            
            if (flag == 1) {
                time++;
            }
        }
        return time;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createMapping(root, target, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};