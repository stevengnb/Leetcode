class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int left = 0;
        long long productSum = 1;
        int totalSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            productSum *= nums[right];

            while (productSum >= k) {
                productSum /= nums[left];
                left++;
            }

            totalSum += (right-left+1);
        }

        return totalSum;
    }
};