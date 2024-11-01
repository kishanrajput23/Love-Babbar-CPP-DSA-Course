// Using Greedy Approach 

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int totalSatisfaction = 0, currentSum = 0;
        
        // Traverse from the last element to the first
        for (int i = satisfaction.size() - 1; i >= 0; --i) {
            // If adding satisfaction[i] increases the total, add it
            if (currentSum + satisfaction[i] > 0) {
                currentSum += satisfaction[i];
                totalSatisfaction += currentSum;
            }
            else {
                break;  // Stop if further additions would decrease the total
            }
        }
        
        return totalSatisfaction;
    }
};
