class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int sum = 0;

        for(int i = 2; i < nums.size(); i++) {
           if(nums[i-2] + nums[i] == double(nums[i-1]/2.0)) sum++; 
        }

        return sum;
    }
};