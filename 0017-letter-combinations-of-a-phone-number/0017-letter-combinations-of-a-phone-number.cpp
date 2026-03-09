class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string path;
        unordered_map<int, string> choices = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"},
        };

        backtrack(ans, choices, path, digits, 0);
        
        return ans;
    }

    void backtrack(vector<string> &ans, unordered_map<int,string> &choices, string &currPath, string &digits, int start) {
        if (currPath.size() == digits.size()) {
            ans.push_back(currPath);
            return;
        } else if (start > digits.size()-1) return;

        char idx = digits[start];

        for (int i = 0; i < choices[idx-'0'].size(); i++) {
            currPath += (choices[idx-'0'][i]);
            backtrack(ans, choices, currPath, digits, start+1);
            currPath.pop_back();
        }
    }
};