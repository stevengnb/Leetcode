class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> positive;

        for (int i : nums) if (i >= 0) positive.push_back(i);
        
        int lenPos = positive.size();
        if (lenPos <= 0) return nums;
        int idx = k % lenPos;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = positive[idx++];
                idx %= lenPos;
            }
        }

        return nums;
    }
};