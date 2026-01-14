class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) return "";

        string s = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != strs[i][j]) {
                    if (j == 0) {
                        return "";
                    } else {
                        s = strs[i].substr(0, j);
                        break;
                    }
                }
            }
        }

        return s;
    }
};