#include<bits/stdc++.h>

void solve(string str, vector<string>& ans, int index) {
    // base case
    if (index >= str.length()) {
        ans.push_back(str);
        return;
    }

    for (int j=index; j<str.length(); j++) {
        swap(str[index], str[j]);
        solve(str, ans, index+1);

        // backtrack
        swap(str[index], str[j]);
    }
}

vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    sort(ans.begin(), ans.end());
    return ans;
}