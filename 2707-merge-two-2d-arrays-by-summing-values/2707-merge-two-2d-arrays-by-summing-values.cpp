class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int left = 0, right = 0;

        while(left < nums1.size() && right < nums2.size()) {
            int leftKey = nums1[left][0];
            int rightKey = nums2[right][0];

            if(leftKey == rightKey) {
                ans.push_back({leftKey, nums1[left][1] + nums2[right][1]});
                left++;
                right++;
            } else if(leftKey < rightKey) {
                ans.push_back({leftKey, nums1[left][1]});
                left++;
            } else {
                ans.push_back({rightKey, nums2[right][1]});
                right++;
            }
        }


        while(left < nums1.size()) {
            ans.push_back({nums1[left][0], nums1[left][1]});
            left++;
        }

        while(right < nums2.size()) {
            ans.push_back({nums2[right][0], nums2[right][1]});
            right++;
        }

        return ans;
    }
};