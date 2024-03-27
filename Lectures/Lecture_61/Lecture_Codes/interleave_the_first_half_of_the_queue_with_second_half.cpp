class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> newQ;
        int n = q.size();
        vector<int> v;
        
        for (int i=0; i<n/2; i++) {
            int ele = q.front();
            q.pop();
            newQ.push(ele);
        }
        
        while (!newQ.empty()) {
            int val1 = newQ.front();
            newQ.pop();
            v.push_back(val1);
            
            int val2 = q.front();
            q.pop();
            v.push_back(val2);
        }
        
        return v;
    }
};