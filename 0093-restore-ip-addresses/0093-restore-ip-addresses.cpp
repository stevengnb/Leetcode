class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string path;

        backtrack(ans, path, s, 0, 0);

        return ans;
    }

    void backtrack(vector<string> &ans, string &path, string &s, int start, int dots) {
        if (dots == 4 && start == s.size()) {
            ans.push_back(path);
            return;
        }

        int num = 0;
        for (int i = 1; i <= 3; i++) {
            if (start + i > s.size()) break;

            num = num * 10 + (s[start+i-1] - '0');

            if (num > 255) break;
            if (i > 1 && s[start] == '0') break;

            int len = path.size();
            path += s.substr(start, i);
            if (dots != 3) path += ".";
            backtrack(ans, path, s, start+i, dots+1);
            path.resize(len);
        }
    }
};