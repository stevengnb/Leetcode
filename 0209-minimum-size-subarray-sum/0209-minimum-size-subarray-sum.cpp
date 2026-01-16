class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minVal = INT_MAX;
        int left = 0;
        int currSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];
            
            if (currSum >= target) minVal = min(minVal, (right-left+1));

            while (currSum >= target) {
                currSum -= nums[left];
                left++;
                if (currSum >= target) minVal = min(minVal, (right-left+1));
            }
        }

        return minVal == INT_MAX ? 0 : minVal;
        
    }
};