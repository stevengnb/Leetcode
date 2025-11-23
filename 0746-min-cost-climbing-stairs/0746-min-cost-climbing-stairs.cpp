class Solution {
public:
    int dp[1001];
    int minVal = INT_MAX;

    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        memset(dp, -1, sizeof(dp));
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= len; i++) {
            if (i == len) {
                dp[i] = min(dp[i-1], dp[i-2]) + 0;
                break;
            }
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
    
        return dp[len];
    }
};