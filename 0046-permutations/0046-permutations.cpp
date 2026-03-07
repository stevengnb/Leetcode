class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int len = nums.size();

        backtrack(ans, nums, path, len);

        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &path, int len) {
        if (path.size() == len) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < len; i++) {
            bool track = false;

            for (int j : path) {
                if (nums[i] == j) {
                    track = true;
                    break;
                }
            }

            if (track) continue;

            path.push_back(nums[i]);
            backtrack(ans, nums, path, len);
            path.pop_back();
        }
    }

    /*
        1 2 3

        path = {}
        1 - path = {1}
            1 - x
            2 - path = {1,2}
                1 - x 
                2 - x
                3 - path = {1,2,3}
            3 - path = {1,3}
                1 - x
                2 - path = {1,2,3}
                3 - x
        2 - path = {2}
            1 - path = {2,1}
                1 - x
                2 - x
                3 - path = {2,1,3}
            2 - x
            3 - path = {2, 3}
                1 - path = {2,3,1}
                2 - x
                3 - x
        3 - path = {3}
            1 - path = {3,1}
                1 - x 
                2 - path = {3,1,2}
                3 - x
            2 - path = {3,2}
                1 - path = {3,2,1}
                2 - x
                3 - x
            3 - x
    */
};