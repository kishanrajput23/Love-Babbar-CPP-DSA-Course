#include <bits/stdc++.h> 
bool isPossibleSolution(int n, int m, vector<int> time, long long mid) {
	int dayCount = 1;
	long long timeCount = 0;

	for (int i=0; i<m; i++) {
		if (timeCount + time[i] <= mid) {
			timeCount += time[i]; 
		}
		else {
			dayCount++;
			if (dayCount>n || time[i]>mid) {
				return false;
			}
			timeCount = time[i];
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long s = 0;
	long long sum = 0;
	for (int i=0; i<m; i++) {
		sum += time[i];
	}
	long long e = sum;

	long long mid = s + (e-s)/2;
	long long ans = -1;

	while (s<=e) {
		if (isPossibleSolution(n, m, time, mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
}