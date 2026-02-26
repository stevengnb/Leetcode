class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1) return 0;
        sort(nums.begin(), nums.end());
        int right = 0;
        int maxVal = 0;

        for (int left = 0; left < len; left++) {
            while (nums[right] <= (long long)nums[left]*k) {
                maxVal = max(maxVal, right-left+1);
                right++;
                if (right > len - 1) break;
            }

            if (right > len - 1) break;
        }

        return len - maxVal;
    }
};