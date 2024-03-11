#include<iostream>
#include<stack>

using namespace std;

int main() {

    stack<char> ch;
    string name = "kishan";
    string ans = "";

    for (int i=0; i<name.length(); i++) {
        ch.push(name[i]);
    }

    while (!ch.empty()) {
        char c = ch.top();
        ans.push_back(c);
        ch.pop();
    }

    cout<<"answer is : "<<ans<<endl;

    return 0;
}