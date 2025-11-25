class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        else if (len == 2) return max(nums[0], nums[1]);
        
        int dp[101];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int temp = dp[1];
        
        for (int i = 0; i <= len-2; i++) {
            if (i < 2) continue;
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        temp = max(temp, dp[len-2]);
        dp[0] = 0;
        dp[1] = nums[1];

        for (int i = 1; i <= len-1; i++) {
            if (i < 2) continue;
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        return max(dp[len-1], temp);
    }
};