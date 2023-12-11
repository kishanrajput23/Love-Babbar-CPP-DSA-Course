class Solution {
public:
    int peak(vector<int>& arr, int start, int end) {
        if (start >= end) {
            return -1;
        }

        int mid = start + (end - start)/2;

        if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) {
            return mid;
        }
        else if (arr[mid] < arr[mid+1]) {
            return peak(arr, mid+1, end);
        }
        else {
            return peak(arr, start, mid);
        }
    }

    int peakIndexInMountainArray(vector<int>& arr) {    
        int start = 0;
        int end = arr.size()-1;
        int ans = peak(arr, start, end);
        return ans;
    }
};