class Solution {
public:
    void solve(string digits, int index, string output, vector<string>& ans, string mapping[]) {
        // checking the index length of
        if(index >= digits.length()) {
            ans.push_back(output);
            return ;
        }

        int number = digits[index] - '0';
        string letter = mapping[number];

        for (int i=0; i<letter.length(); i++) {
            output.push_back(letter[i]);
            solve(digits, index+1, output, ans, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length()==0) {
            return ans;
        }
        int index = 0;
        string output = "";

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, index, output, ans, mapping);
        return ans;
    }
};