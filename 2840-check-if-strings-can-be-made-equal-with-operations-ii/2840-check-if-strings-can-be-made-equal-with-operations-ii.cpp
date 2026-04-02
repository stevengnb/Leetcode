class Solution {
public:
    bool checkStrings(string s1, string s2) {

        int len = s1.size();

        for (int i = 0; i < len-2; i++) {
            if (s1[i] == s2[i]) continue;
            bool flag = false;

            for (int j = i+2; j < len; j+=2) {
                if (s1[j] == s2[i]) {
                    // ketemu yg sama
                    int temp = s1[j];
                    s1[j] = s1[i];
                    s1[i] = temp;
                    flag = true;
                    break;
                }
            }

            if (!flag) return false;
        }
        
        if (len < 2) {
            for (int i = 0; i < len; i++) if (s1[i] != s2[i]) return false;
        } else {
            for (int i = len-2; i < len; i++) if (s1[i] != s2[i]) return false;
        }
        return true;
    }
};
