class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> currPath;

        backtrack(ans, currPath, n, k, 1);

        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& currPath, int range, int limit, int start) {
        if (currPath.size() == limit) {
            ans.push_back(currPath);
            return;
        }

        for (int i = start; i <= range; i++) {
            if (currPath.size() > 0 && i <= currPath.back()) continue;
            currPath.push_back(i);
            backtrack(ans, currPath, range, limit, start+1);
            currPath.pop_back();
        }
    }
};