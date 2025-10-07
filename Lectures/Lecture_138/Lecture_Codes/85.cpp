/*
85. Maximal Rectangle
Problem: Find the largest rectangle containing only 1's in a binary matrix

Approach: Convert to "Largest Rectangle in Histogram" problem
- For each row, treat it as the base of a histogram
- Height of each bar = consecutive 1's ending at current row
- Apply histogram algorithm to find max rectangle for each row configuration

Time Complexity: O(m × n) where m = rows, n = cols
Space Complexity: O(n) for auxiliary arrays
*/

class Solution {
public:

    // Function to find Next Smaller Right (NSR) for each element
    // NSR[i] = index of first smaller element to the right of i
    vector<int> getNSR(vector<int> arr, int n) {
        stack<int> st;           // Stack to store indices
        vector<int> NSR(n);      // Result array
        
        // Traverse from right to left
        for (int i = n-1; i >= 0; i--) {
            // If stack is empty, no smaller element to the right
            if (st.empty()) {
                NSR[i] = n;  // Use n as boundary (beyond array)
            }
            else {
                // Pop elements that are >= current element
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                
                // After popping, check if stack is empty
                if (st.empty()) {
                    NSR[i] = n;  // No smaller element found
                }
                else {
                    NSR[i] = st.top();  // Top element is the next smaller
                }
            }
            // Push current index to stack
            st.push(i);
        }
        return NSR;
    }

    // Function to find Next Smaller Left (NSL) for each element
    // NSL[i] = index of first smaller element to the left of i
    vector<int> getNSL(vector<int> arr, int n) {
        stack<int> st;           // Stack to store indices
        vector<int> NSL(n);      // Result array
        
        // Traverse from left to right
        for (int i = 0; i < n; i++) {
            // If stack is empty, no smaller element to the left
            if (st.empty()) {
                NSL[i] = -1;  // Use -1 as boundary (before array)
            }
            else {
                // Pop elements that are >= current element
                while (!st.empty() && arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                
                // After popping, check if stack is empty
                if (st.empty()) {
                    NSL[i] = -1;  // No smaller element found
                }
                else {
                    NSL[i] = st.top();  // Top element is the next smaller
                }
            }
            // Push current index to stack
            st.push(i);
        }
        return NSL;
    }

    // Function to find maximum rectangle area in histogram
    // Uses the concept: for each bar, find max rectangle with this bar as height
    int findMaxArea(vector<int> height, int n) {
        // Step 1: Find NSR and NSL for all elements
        vector<int> NSR = getNSR(height, n);  // Next smaller to right
        vector<int> NSL = getNSL(height, n);  // Next smaller to left
        
        // Step 2: Calculate width for each bar
        vector<int> width(n);
        for (int i = 0; i < n; i++) {
            // Width = distance between NSL and NSR - 1
            // This gives the range where height[i] is the minimum
            width[i] = NSR[i] - NSL[i] - 1;
        }
        
        // Step 3: Calculate maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            // Area with height[i] as the limiting height
            int area = width[i] * height[i];
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }

    // Main function to find maximal rectangle in binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns
        
        // Height array to store histogram heights for current row
        vector<int> height(n, 0);
        
        // Step 1: Initialize height array with first row
        // Convert '1' to 1 and '0' to 0
        for (int i = 0; i < n; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }
        
        // Step 2: Find max area for first row configuration
        int maxArea = findMaxArea(height, n);
        
        // Step 3: Process remaining rows
        for (int row = 1; row < m; row++) {
            // Update height array for current row
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '0') {
                    // If current cell is '0', reset height to 0
                    height[col] = 0;
                }
                else {
                    // If current cell is '1', increment height
                    // This represents consecutive 1's ending at current row
                    height[col] += 1;
                }
            }
            
            // Find max rectangle area for current histogram configuration
            maxArea = max(maxArea, findMaxArea(height, n));
        }
        
        return maxArea;
    }
};

/*
ALGORITHM EXPLANATION:

Key Insight: Convert 2D matrix problem to multiple 1D histogram problems

Example: matrix = [["1","0","1","0","0"],
                   ["1","0","1","1","1"], 
                   ["1","1","1","1","1"],
                   ["1","0","0","1","0"]]

Row-wise histogram heights:
Row 0: [1, 0, 1, 0, 0] (first row)
Row 1: [2, 0, 2, 1, 1] (cumulative heights)
Row 2: [3, 1, 3, 2, 2] (cumulative heights)
Row 3: [4, 0, 0, 3, 0] (reset where '0' appears)

For each histogram, find largest rectangle using stack-based approach:

Histogram Algorithm:
1. For each bar at index i, find the largest rectangle with height[i] as minimum height
2. This requires finding NSL[i] and NSR[i] (next smaller elements)
3. Width of rectangle = NSR[i] - NSL[i] - 1
4. Area = width × height[i]

Stack Usage:
- Maintains indices in increasing order of heights
- When smaller element found, pop and calculate areas
- Efficiently finds NSL and NSR in O(n) time

Time Complexity Analysis:
- For each row: O(n) to update heights + O(n) for histogram = O(n)
- Total: O(m × n)

Space Complexity: O(n) for height array and stack operations

This approach transforms a complex 2D problem into simpler 1D subproblems!
*/