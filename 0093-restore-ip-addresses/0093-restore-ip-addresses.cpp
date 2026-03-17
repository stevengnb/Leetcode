class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string path;

        backtrack(ans, path, s, 0, 0, "");

        return ans;
    }

    void backtrack(vector<string> &ans, string &path, string &s, int start, int dots, string curr) {
        if (curr != "" && (stoi(curr) < 0 || stoi(curr) > 255)) return;
        if (curr.size() >= 2 && curr[0] == '0') return;

        if (dots == 4 && start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 1; i <= 3; i++) {
            if (start + i > s.size()) break;

            int len = path.size();
            string now = s.substr(start, i);

            path += now;
            if (dots != 3) path += ".";
            backtrack(ans, path, s, start+i, dots+1, now);
            path.resize(len);
        }
    }
};