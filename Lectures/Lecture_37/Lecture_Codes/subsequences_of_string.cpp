#include <bits/stdc++.h> 

void solve(string str, string output, int index, vector<string>& ans) {
	if (index >= str.length()) {
		if (output.length() > 0) {
			ans.push_back(output);
		}
		return;
	}

	// exclude
	solve(str, output, index+1, ans);

	// include
	output.push_back(str[index]);
	solve(str, output, index+1, ans);

}
vector<string> subsequences(string str){
	// Write your code here
	int index = 0;
	string output = "";
	vector<string> ans;
	solve(str, output, index, ans);
	return ans;
	
}
