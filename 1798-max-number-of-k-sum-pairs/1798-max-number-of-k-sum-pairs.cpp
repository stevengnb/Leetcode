class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left = 0; 
        int right = nums.size() - 1;
        int sum = 0;

        sort(nums.begin(), nums.end());        

        while(left < right) {
            if(nums[left] + nums[right] == k) {
                sum++;
                left++;
                right--;
            } else if(nums[left] + nums[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        
        return sum;
    }
};