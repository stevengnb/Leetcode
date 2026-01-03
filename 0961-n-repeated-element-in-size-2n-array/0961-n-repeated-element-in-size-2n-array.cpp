class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> vect(10001, 0);

        for (int i = 0; i < nums.size(); i++) {
            vect[nums[i]] += 1;
            if (vect[nums[i]] >= nums.size()/2) return nums[i];
        }

        return -1;
    }
};