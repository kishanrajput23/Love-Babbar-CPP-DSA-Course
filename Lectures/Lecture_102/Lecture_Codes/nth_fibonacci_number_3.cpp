// space optimization

#include<bits/stdc++.h>
using namespace std;
int main() {
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;

        int prev1 = 1;
        int prev2 = 0;

        if (n == 0) {
                return prev2;
        }

        for (int i=2; i<=n; i++) {
                int curr = prev1 + prev2;

                // shift prevs
                prev2 = prev1;
                prev1 = curr;
        }

        cout<<prev1<<endl;

        return 0;
}