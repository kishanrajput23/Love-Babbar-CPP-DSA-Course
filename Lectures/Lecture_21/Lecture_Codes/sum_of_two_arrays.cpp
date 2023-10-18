#include <bits/stdc++.h> 
#include <cmath>
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	// converting array 'a' elements into a number
    int num1 = 0;
    int cnt1 = 1;
    for (int i=0; i<n; i++) {
		num1 += a[i] * pow(10, n-cnt1);
		cnt1++;
	}
	
	// converting array 'b' elements into a number
    int num2 = 0;
    int cnt2 = 1;
    for (int i=0; i<m; i++) {
		num2 += b[i] * pow(10, m-cnt2);
		cnt2++;
	}

	int sum = num1+num2;
	int k = (log10(sum) + 1);  // return the count of digits in sum

	// converting sum of two numbers into an array
	vector<int> arr(k);
	for (int i=k-1; i>=0; i--) {
        arr[i] = sum%10;
        sum /= 10;
    }

	return arr;
}