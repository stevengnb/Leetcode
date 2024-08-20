class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, k = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> nums3;
        
        while(i < len1 && j < len2) {
            if(nums1[i] <= nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }

        while(i < len1) nums3.push_back(nums1[i++]);
        while(j < len2) nums3.push_back(nums2[j++]);

        int mid = nums3.size()/2;

        if(nums3.size() % 2 == 1) return nums3[mid];
        else return (nums3[mid]+nums3[mid-1])/2.0;
    }
};