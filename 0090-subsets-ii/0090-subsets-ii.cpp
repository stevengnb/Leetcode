class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(nums.begin(), nums.end());
        backtrack(ans, nums, path, 0);

        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &path, int start) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;

            path.push_back(nums[i]);
            backtrack(ans, nums, path, i+1);
            path.pop_back();
            cout << endl;
        }
    }
};