class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int temp;

        while(right < nums.size()) {
            if(nums[left] != 0) {
                left++;
            } else if(nums[left] == 0 && nums[right] != 0) {
                temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
            }
            right++;
        }
    }
};