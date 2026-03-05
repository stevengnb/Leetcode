class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currPath;

        sort(candidates.begin(), candidates.end());
        backtrack(ans, candidates, currPath, target, 0, 0);

        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& currPath, int target, int sum, int start) {
        if (sum == target) {
            ans.push_back(currPath);
            return;
        } else if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            int cand = candidates[i];

            if (i > start && candidates[i] == candidates[i-1]) continue;
            if (cand + sum > target) break;

            sum += cand;
            currPath.push_back(cand);
            backtrack(ans, candidates, currPath, target, sum, i+1);
            currPath.pop_back();
            sum -= cand;
        }

    }
};