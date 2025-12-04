class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 10 9 2 5 3 7 101 18
        // 1  1 1 2 2 3 4   4 
        
        vector<int> dp(nums.size()+1, 1);
        int maxVal = INT_MIN;
        int temp;

        for (int i = 0; i < nums.size(); i++) {
            temp = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    temp = max(temp, dp[j]);
                }
            }
            dp[i] = temp + 1;
            maxVal = max(maxVal, dp[i]);
        }

        return maxVal;
    }
};