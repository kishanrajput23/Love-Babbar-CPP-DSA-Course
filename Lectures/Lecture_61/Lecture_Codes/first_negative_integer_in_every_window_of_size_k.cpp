vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        deque<long long int> dq;
        vector<long long> result;
        
        // process first window of k size
        for (int i=0; i<K; i++) {
            if (A[i] < 0) {
                dq.push_back(i);
            }
        }
        
        // store answer of first k size window to result
        if (dq.size() > 0) {
            result.push_back(A[dq.front()]);
        }
        else {
            result.push_back(0);
        }
        
        // processing for remaining windows
        for (int i=K; i<N; i++) {
            // removal
            
            if (!dq.empty() && i-dq.front() >= K) {
                dq.pop_front();
            }
            
            // addition
            if (A[i] < 0) {
                dq.push_back(i);
            }
            
            // storing element
            if (dq.size() > 0) {
                result.push_back(A[dq.front()]);
            }
            else {
                result.push_back(0);
            }
             
        }
        return result;
                                                 
 }