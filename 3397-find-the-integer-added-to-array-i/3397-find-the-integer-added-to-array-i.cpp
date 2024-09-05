class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int minNum1 = INT_MAX, minNum2 = INT_MAX;

        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] < minNum1) minNum1 = nums1[i];
            if(nums2[i] < minNum2) minNum2 = nums2[i];
        }

        return minNum2 - minNum1;
    }
};