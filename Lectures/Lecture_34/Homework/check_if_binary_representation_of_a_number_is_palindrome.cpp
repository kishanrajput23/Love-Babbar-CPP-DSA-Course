#include <bits/stdc++.h> 

bool isPalindrome(vector<int>&ans, int i, int j){

  	if (i > j) {
    	return true;
  	}

    if (ans[i] != ans[j]) {
        return false;
    }
	else {
        return isPalindrome(ans, i+1, j-1);
    }
}


bool checkPalindrome(long long N)
{
	// Write your code here.
	vector<int>ans;
    
	while (N!=0) {
        if (N&1) {
            ans.push_back(1);
		}
		else {
            ans.push_back(0);
		}
        N = N >> 1;
    }

    return isPalindrome(ans, 0, ans.size()-1);
}