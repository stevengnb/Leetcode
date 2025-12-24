class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int size = nums.size();
        int left = 0, right = size - 1;

        if (nums[left] >= 0) {
            for (int i : nums) ans.push_back(pow(i, 2));
        } else if (nums[right] < 0) {
            for (int i = size - 1; i >= 0; i--) ans.push_back(pow(nums[i], 2));
        } else {
            for (int i = 0; i < size; i++) {
                if (nums[i] >= 0) {
                    right = i;
                    left = i-1;
                    break;
                }
            }

            while (left >= 0 && right < size) {
                if (pow(nums[left], 2) <= pow(nums[right], 2)) {
                    ans.push_back(pow(nums[left], 2));
                    left--;
                } else {
                    ans.push_back(pow(nums[right], 2));
                    right++;
                }
            }

            while (left >= 0) {
                ans.push_back(pow(nums[left], 2));
                left--;
            }

            while (right < size) {
                ans.push_back(pow(nums[right], 2));
                right++;
            }
        }

        return ans;
    }
};