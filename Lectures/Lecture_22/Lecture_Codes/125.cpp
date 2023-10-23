class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;

        while(start<=end) {
            if (!isalnum(tolower(s[start]))) {
                start++;
            }
            else if (!isalnum(tolower(s[end]))) {
            end--;
            }
            else if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            else {
                start++;
                end--;
            }
        }
        return true;
    }
};


// Alernate Solution


// class Solution {

//     bool isValidChar(char ch) {
//         if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
//             return 1;
//         }
//         return 0;
//     }

//     char toLowerCase(char ch) {
//         if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
//             return ch;
//         }
//         else {
//             return ch - 'A' + 'a';
//         }
//     }

//     bool isValidPalindrome(string temp) {
//         int start = 0;
//         int end = temp.length()-1;

//         while(start<=end) {
//             if (temp[start] != temp[end]) {
//                 return false;
//             }
//             else {
//                 start++;
//                 end--;
//             }
//         }
//         return true;
//     }

// public:
//     bool isPalindrome(string s) {
//         string temp = "";
//         for (int i=0; i<s.length(); i++) {
//             if (isValidChar(s[i])) {
//                 temp.push_back(s[i]);
//             }
//         }

//         for (int j=0; j<temp.length(); j++) {
//             temp[j] = toLowerCase(temp[j]);
//         }

//         return isValidPalindrome(temp);
//     }
// };