class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> currPath;
        backtrack(answer, currPath, nums, 0);
        return answer;
    }

    void backtrack(vector<vector<int>> &answer, vector<int> &currPath, vector<int> &options, int index) {
        answer.push_back(currPath);

        for (int i = index; i < options.size(); i++) {
            currPath.push_back(options[i]);
            backtrack(answer, currPath, options, i+1);
            currPath.pop_back();
        }
    }
};