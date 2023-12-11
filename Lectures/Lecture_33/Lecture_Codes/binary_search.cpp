int binarySearch(vector<int> &nums, int start, int end, int key) {
    if (start > end) {
        return -1;
    }

    int mid  = start + (end - start)/2;

    if (nums[mid] == key) {
        return mid;
    }
    
    if (nums[mid]<key) {
        return binarySearch(nums, mid+1, end, key);
    }
    else {
        return binarySearch(nums, start, mid-1, key);
    }
}

int search(vector<int> &nums, int target) {
    // Write your code here.
    int n = nums.size();
    int ans  = binarySearch(nums, 0, n, target);
    return ans;
}