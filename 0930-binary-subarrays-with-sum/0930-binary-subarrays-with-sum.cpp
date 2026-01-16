class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int totalLt = 0;
        int totalLo = 0;
        int left = 0;
        int currSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];

            while (currSum > goal) {
                currSum -= nums[left];
                left++;
            }

            if (currSum <= goal) totalLt += (right-left+1);
        }

        if (goal == 0) return totalLt;
        left = 0;
        currSum = 0;
        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];

            while (currSum >= goal) {
                currSum -= nums[left];
                left++;
            }

            if (currSum <= (goal - 1)) totalLo += (right-left+1);
        }

        return totalLt - totalLo;
    }
};