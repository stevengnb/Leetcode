class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        backtrack(ans, candidates, path, 0, target);

        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& path, int sum, int target) {
        if (sum > target) return;
        else if (sum == target) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            int cand = candidates[i];
            if (!path.empty() && path.back() < cand) continue;

            sum += cand;
            path.push_back(cand);

            backtrack(ans, candidates, path, sum, target);

            path.pop_back();
            sum -= cand;
        }
    }
};