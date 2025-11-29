class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int coinLen = coins.size();

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coinLen; j++) {
                if (coins[j] > i) continue;
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};