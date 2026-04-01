class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int len = s1.size();

        for (int i = 0; i < len-2; i++) {
            if (s1[i] == s2[i]) continue;
            
            if (s1[i+2] == s2[i]) {
                // swap?
                int temp = s1[i+2];
                s1[i+2] = s1[i];
                s1[i] = temp;
            } else {
                return false;
            }
        }

        for (int i = len-2; i < len; i++) if (s1[i] != s2[i]) return false;

        /*
            ifjz -> jzfi

            i = 0
            swap
            s1 = JFIZ
            s2 = JZFI

            i = 1
            swap
            s1 = JZIF
            s2 = JZFI

        */

        return true;
    }
};