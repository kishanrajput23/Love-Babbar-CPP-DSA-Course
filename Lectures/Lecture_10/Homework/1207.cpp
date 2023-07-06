class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //sorting the given array
        sort(arr.begin(), arr.end());
        vector<int> v; //intialise new vector
        int count = 1; 

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            } else {
                v.push_back(count);
                count = 1;
            }
        }
        v.push_back(count);

        sort(v.begin(), v.end());

        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                return false;
            }
        }

        return true;
    }
};