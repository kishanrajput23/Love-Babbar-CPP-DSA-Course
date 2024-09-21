// Recursion --> Gives TLE

class Solution {
public:
    int solve(int n, vector<int> &days, vector<int> &costs, int index) {
        // base case
        if (index >= n) {
            return 0;
        }

        // 1 day pass
        int option1 = solve(n, days, costs, index+1) +costs[0];
    
        // 7 day pass
        int i;
        for (i=index; i<n && days[i]<days[index]+7; i++);
        int option2 = solve(n, days, costs, i) + costs[1];

        // 30 day pass
        for (i=index; i<n && days[i]<days[index]+30; i++);
        int option3 = solve(n, days, costs, i) +costs[2];

        int ans = min(option1, min(option2, option3));

        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(n, days, costs, 0); 
    }
};