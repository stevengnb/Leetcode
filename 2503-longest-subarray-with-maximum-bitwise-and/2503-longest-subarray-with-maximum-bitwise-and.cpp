class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int counter = 0;
        int longestSubarray = INT_MIN;
        int maxVal = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
                counter = 1;
                longestSubarray = counter;
            } else if(nums[i] == maxVal) {
                counter++;
                longestSubarray = max(counter, longestSubarray);
            } else {
                counter = 0;
            }
        }

        return longestSubarray;
    }
};