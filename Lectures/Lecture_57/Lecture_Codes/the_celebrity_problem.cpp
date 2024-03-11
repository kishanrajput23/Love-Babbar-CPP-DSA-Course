class Solution 
{
    public:
    bool knows(vector<vector<int> >& M, int a, int b) {
        if (M[a][b] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        // step 1: put elements into stack
        stack<int> st;
        for (int i=0; i<n; i++) {
            st.push(i);
        }
        
        // step 2 : take two elememts and check whether they knows each other or not
        while (st.size() > 1) {
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if (knows(M, a, b)) {
                st.push(b);
            }
            else {
                st.push(a);
            }
        }
        
        // step 3: check rows of potential candidate and it should be 0
        bool rowCheck = false;
        int celebrity = st.top();
        int zeroCount = 0;
        
        for (int i=0; i<n; i++) {
            if (M[celebrity][i] == 0) {
                zeroCount++;
            }
        }
        
        if (zeroCount == n) {
            rowCheck = true;
        }
        
        // step 4 : check columns of potential candiate and it should be 1
        bool columnCheck = false;
        int oneCount = 0;
        
        for (int i=0; i<n; i++) {
            if (M[i][celebrity] == 1) {
                oneCount++;
            }
        }
        
        if (oneCount == n-1) {
            columnCheck = true;
        }
        
        if (rowCheck == true && columnCheck == true) {
            return celebrity;
        }
        else {
            return -1;
        }
    }
};