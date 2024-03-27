class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s;
        
        // step 1 : put first k elements to stack
        for (int i=0; i<k; i++) {
            int n = q.front();
            q.pop();
            s.push(n);
        }
        
        // step 2 : while stack is not empty push all elements in queue
        while(!s.empty()) {
            int n = s.top();
            s.pop();
            q.push(n);
        }
        
        // step 3 : now pop first n-k elements from queue and push back into queue again
        for (int i=0; i<q.size()-k; i++) {
            int n = q.front();
            q.pop();
            q.push(n);
        }
        
        return q;
    }
};