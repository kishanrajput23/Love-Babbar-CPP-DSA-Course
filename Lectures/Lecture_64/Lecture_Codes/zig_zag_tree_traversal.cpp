//User function Template for C++
/*Structure of the node of the binary tree is as
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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root) {
    	vector<int> ans;
    	
        // 	base case
    	if (root == NULL) {
    	    return ans;
    	}
    	
    	queue<Node*> q;
    	q.push(root);
    	
        // for making traversal zig zag 	
    	bool leftToRight = true;
    	
    	while (!q.empty()) {
    	    int size = q.size();
    	    vector<int> temp(size);
    	    
    	   // processing levels
    	    for (int i=0; i<size; i++) {
    	        Node* frontNode = q.front();
    	        q.pop();
    	        
    	        int index = leftToRight ? i : size - 1 - i;
    	        
    	        temp[index] = frontNode->data;
    	        
    	        if (frontNode->left != NULL) {
    	            q.push(frontNode->left);
    	        }
    	        
    	        if (frontNode->right != NULL) {
    	            q.push(frontNode->right);
    	        }
    	    }
    	    
    	    leftToRight = !leftToRight;
    	    
    	    for (auto i : temp) {
    	        ans.push_back(i);
    	    }
    	}
    	
    	return ans;
    }
};