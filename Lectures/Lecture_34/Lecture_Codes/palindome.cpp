#include<iostream>
using namespace std;

bool checkPalindrome(string& str, int i, int j) {
    if (i>j) {
        return true;
    }

    if (str[i] != str[j]) {
        return false;
    }
    else {
        return checkPalindrome(str, i+1, j-1);
    }
}


int main() {

    string str = "abcddcba";

    bool ans =  checkPalindrome(str, 0, str.length()-1);

    if (ans) {
        cout<<"Gieven string is palindrome"<<endl;
    }
    else {
        cout<<"Given string is not palindrome"<<endl;
    }

    return 0;
}