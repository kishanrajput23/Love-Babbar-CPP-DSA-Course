// bottom up approach

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

        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i=2; i<=n; i++) {
                dp[i] = dp[i-1] + dp[i-2];
        }

        cout<<dp[n]<<endl;

        return 0;
}