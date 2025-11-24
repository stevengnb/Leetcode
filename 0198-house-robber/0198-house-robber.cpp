class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return nums[0];
        } else if (len == 2) {
            return max(nums[0], nums[1]);
        }

        int dp[401];
        memset(dp, -1, sizeof(dp));
        dp[0] = nums[0];
        dp[1] = nums[1];
        int maxVal = max(dp[0], dp[1]);

        for (int i = 2; i < len; i++) {
            if (i == 2) dp[i] = dp[i-2] + nums[i];
            else dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
            maxVal = max(maxVal, dp[i]);
        }

        return maxVal;
    }
};