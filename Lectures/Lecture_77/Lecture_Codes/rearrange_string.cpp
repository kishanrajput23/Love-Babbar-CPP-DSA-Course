#include <bits/stdc++.h> 

string reArrangeString(string &s) {
	// Write your code here.
	int n = s.size();
	unordered_map<char, int> mp;

	for (auto i : s) {
		mp[i]++;

		if (mp[i] > (n+1)/2) {      
        // if a character repeats more than (n+1)/2 times then it's not possible to rearrange that string
			return "not possible";
		}
	}

	// max heap
	priority_queue<pair<int, char>> pq;

	for (auto i : mp) {
		pq.push({i.second, i.first});
	}

	string result = "";

	while (pq.size() >= 2) {
		auto p1 = pq.top();
		pq.pop();

		auto p2 = pq.top();
		pq.pop();

		result.push_back(p1.second);
		p1.first--;

		result.push_back(p2.second);
		p2.first--;		

		if (p1.first > 0) {
			pq.push(p1);
		}

		if (p2.first > 0) {
			pq.push(p2);
		}
	}

	if (!pq.empty()) {
		result.push_back(pq.top().second);
	}

	return result;
}
