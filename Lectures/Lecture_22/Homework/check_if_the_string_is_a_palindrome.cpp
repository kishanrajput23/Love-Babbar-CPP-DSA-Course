#include <bits/stdc++.h> 

bool checkPalindrome(string s)
{
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