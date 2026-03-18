class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        backtrack(ans, path, 0, s);

        return ans;
    }

    void backtrack(vector<vector<string>> &ans, vector<string> &path, int start, string s) {
        if (start == s.size()) {
            ans.push_back(path);
        }

        for (int i = 1; i <= s.size(); i++) {
            if (start + i > s.size()) break;
            string add = s.substr(start, i);
            if (!isPalindrome(add)) continue;

            path.push_back(add);
            backtrack(ans, path, start+i, s);
            path.pop_back();
        }

    }

    bool isPalindrome(string s) {
        int len = s.size();
        for (int i = 0; i < len/2; i++) {
            if (s[i] != s[len-i-1]) return false;
        }
        return true;
    }
};