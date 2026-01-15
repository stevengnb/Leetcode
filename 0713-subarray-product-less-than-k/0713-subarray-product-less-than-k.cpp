class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        // int right = 0;
        int productSum = 1;
        int totalSum = 0;

        // while (left < nums.size()) {

        // }

        for (int right = 0; right < nums.size(); right++) {
            productSum *= nums[right];
            if (productSum < k) totalSum++;
            
            if (productSum >= k || right == nums.size() - 1) {
                left++;
                right = left;
                productSum = nums[left];
                if (productSum < k) totalSum++; 
            }
        }

        return totalSum;
    }
};