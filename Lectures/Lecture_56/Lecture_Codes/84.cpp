class Solution {
public:

    vector<int> nextSmallerElements(vector<int> arr, int n) {
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

    vector<int> prevSmallerElements(vector<int> arr, int n) {
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

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
};