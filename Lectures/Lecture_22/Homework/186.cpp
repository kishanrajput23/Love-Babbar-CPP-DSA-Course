class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int i = 0, j = 0;
        while(i < str.size()) {
            int j = i;
            while (j < str.size() && str[j] != ' ')
            {
                 ++j;
            }            
            reverse(str.begin()+i, str.begin()+j);
            i = j + 1;
        }
    }
};