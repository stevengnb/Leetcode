class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;   
        unordered_map<int, int> map;

        for(int i : nums2) {
            map[i]++;
        }

        for(int i = 0; i < nums1.size(); i++) {
            if(map[nums1[i]] != 0) {
                ans.push_back(nums1[i]);
                map[nums1[i]]--;
            }
        }

        return ans;
    }
};