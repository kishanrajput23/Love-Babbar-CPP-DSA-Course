#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for (int i=0; i<s.length(); i++) {
        char ch = s[i];
        if (ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/') {
            st.push(ch);
        }
        else {
            if (ch == ')') {
                bool isRedundant = true;
                while (st.top() != '(') {
                    char up = st.top();
                    if (up=='+' || up=='-' || up=='*' || up=='/') {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
