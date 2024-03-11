class Solution{
  public:
    vector<int> nextSmallerElements(int* arr, int n) {
        vector<int> v(n);
        stack<int> s;
        s.push(-1);

        for (int i=n-1; i>=0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    vector<int> prevSmallerElements(int* arr, int n) {
        vector<int> v(n);
        stack<int> s;
        s.push(-1);

        for (int i=0; i<n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            v[i] = s.top();
            s.push(i);
        }
        return v;
    }

    int largestRectangleArea(int* heights, int n) {
        // int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElements(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElements(heights, n);

        int area = INT_MIN;

        for (int i=0; i<n; i++) {
            int l = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;

            int ans = l*b;
            area = max(area, ans);
        }
        return area;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        // step 1 : compute area for first row
        int area = largestRectangleArea(M[0], m);
        
        // step 1 : compute area for remaining rows
        for (int i=1; i<n; i++) {
            for (int j=0; j<m; j++) {
                
                // updating rows values with previous one
                if (M[i][j] != 0) {
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else {
                    M[i][j] = 0;
                }
            }
            
            // entire row is updated now
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
        
    }
};