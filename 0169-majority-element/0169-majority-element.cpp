class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ans;

        int max = INT_MIN;
        int major = -1;

        for(int i = 0; i < nums.size(); i++) {
            int now = ans[nums[i]];

            ans[nums[i]]++;
            if(now > max) {
                max = now;
                major = nums[i]; 
            }
        }

        return major;
    }
};