class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        backtrack(ans, candidates, path, 0, target, 0);

        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& path, int sum, int target, int start) {
        if (sum > target) return;
        else if (sum == target) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            int cand = candidates[i];
            sum += cand;
            path.push_back(cand);

            backtrack(ans, candidates, path, sum, target, i);

            path.pop_back();
            sum -= cand;
        }
    }
};