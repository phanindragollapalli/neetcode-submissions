class Solution {
public:
    int minCostClimbingStairs(vector<int>& height) {
        int n = height.size();

        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int i = 2; i <= n; i++) {
            int curr = min(
                prev1 + height[i - 1],
                prev2 + height[i - 2]
            );

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};