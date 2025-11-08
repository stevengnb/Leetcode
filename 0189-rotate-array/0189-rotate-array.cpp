class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int start = k % size;
        vector<int> ans;

        for (int i = size - start; i < size; i++) ans.push_back(nums[i]);
        for (int i = 0; i < size - start; i++) ans.push_back(nums[i]);

        nums = ans;
    }
};