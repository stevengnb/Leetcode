class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int totalT = 0, totalO = 00;
        int currSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) currSum++;

            while (currSum > k) {
                if (nums[left] % 2 == 1) currSum--;
                left++;
            }
            
            if (currSum <= k) totalT += (right-left+1);
        }
        if (k - 1 < 0) return 0;

        left = 0;
        currSum = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) currSum++;

            while (currSum > k - 1) {
                if (nums[left] % 2 == 1) currSum--;
                left++;
            }

            if (currSum <= k - 1) totalO += (right-left+1);
        }

        return totalT - totalO;
    }
};