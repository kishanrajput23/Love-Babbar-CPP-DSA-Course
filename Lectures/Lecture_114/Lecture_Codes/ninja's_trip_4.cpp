// space optimization

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    // Write your code here.
    int ans = 0;

    queue<pair<int, int>> week;
    queue<pair<int, int>> month;

    for (auto day : days) {
        // step 1 : remove expired days
        while (!week.empty() && week.front().first+7 <= day) {
            week.pop();
        }

        while (!month.empty() && month.front().first+30 <= day) {
            month.pop();
        }

        // step 2 : add cost for current day
        week.push({day, ans+cost[1]});
        month.push({day, ans+cost[2]});

        // step 3 : update ans

        ans = min(ans+cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}