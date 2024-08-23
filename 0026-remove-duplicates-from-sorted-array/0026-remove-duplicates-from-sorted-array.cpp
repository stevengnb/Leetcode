class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i;
        int curr = 0;

        for(i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                curr++;
                nums[curr] = nums[i];
            }

            if(nums[i] < nums[curr]) break;
        }

        return curr+1;
    }
};