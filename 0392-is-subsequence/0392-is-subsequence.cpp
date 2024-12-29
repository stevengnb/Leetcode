class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0 && t.length() == 0) return true;
        else if(t.length() == 0) return false;

        int idx = 0;

        for(char c : t) {
            // cout << "t = " << c << endl;
            // cout << "s = " << s[idx] << endl << endl;
            if(c == s[idx]) idx++;
            if(idx >= s.length()) return true;
        }

        return false;
    }
};