class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_map<int, bool> map;
        int len = nums.size();

        sort(nums.begin(), nums.end());
        backtrack(ans, nums, path, map, len);

        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &path, unordered_map<int,bool> &map, int len) {
        if (path.size() == len) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1] && !map[i-1]) continue;
            if (map[i]) continue;

            path.push_back(nums[i]);
            map[i] = true;

            backtrack(ans, nums, path, map, len);

            path.pop_back();
            map[i] = false;
        }
    }

    /*
    
        1 1 2

        1 - path = {1}
            1 - x
            1 - path = {1,1}
                1 - x
                1 - x
                2 - path = {1,1,2}
                    1 - x
                    1 - x
                    2 - x
            2 - path = {1,2}
                1 - x
                1 - path = {1,2,1}
                2 - x
        1 - x
        2 - path = {2}
            1 - path = {2,1}
                1 - x
                1 - path = {2,1,1}
                2 - x
            1 = x
            2 - x
    */
};