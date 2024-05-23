// TC = O(k^2 log(k))
// SC = O(nk)

class Solution {
    public:
    
    void merge(vector<int> &arr, int start, int mid, int end) {
        int len1 = mid - start + 1;     // length of first array
        int len2 = end - mid;           // length of the second array

        vector<int> first(len1);        // creating first array
        vector<int> second(len2);       // creating second array

        // copying values into arrays
        for (int i = 0; i < len1; i++) {
            first[i] = arr[start + i];
        }

        for (int i = 0; i < len2; i++) {
            second[i] = arr[mid + 1 + i];
        }

        // merging two arrays
        int index1 = 0;
        int index2 = 0;
        int mainArrayIndex = start;

        while (index1 < len1 && index2 < len2) {
            if (first[index1] < second[index2]) {
                arr[mainArrayIndex++] = first[index1++];
            } else {
                arr[mainArrayIndex++] = second[index2++];
            }
        }

        // Copy remaining elements of first[] if any
        while (index1 < len1) {
            arr[mainArrayIndex++] = first[index1++];
        }

        // Copy remaining elements of second[] if any
        while (index2 < len2) {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    void solve(vector<int> &arr, int start, int end, int portion, int K) {
        if (portion < 2) {
            return ;
        }

        int mid = start + (portion/2) * K -1;

        // sorting left part of the array
        solve(arr, start, mid, portion/2, K);

        // sorting right part of the array
        solve(arr, mid+1, end, portion-portion/2, K);

        // merging two sorted arrays
        merge(arr, start, mid, end);
    }
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {

        vector<int> ans;

        for (int i=0; i<K; i++) {
            for (int j=0; j<arr[i].size(); j++) {
                ans.push_back(arr[i][j]);
            }
        }
        
        solve(ans, 0, ans.size()-1, K, K);
        
        return ans;
    }
};