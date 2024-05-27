int maximumFrequency(vector<int> &arr, int n) {
    //Write your code here
    int maxFreq = 0;

    unordered_map<int, int> mp;

    for (auto i : arr) {
        mp[i]++;
        maxFreq = max(maxFreq, mp[i]);
    }

    for (auto i : arr) {
        if (mp[i] == maxFreq) {
           return i;
        }
    }
}