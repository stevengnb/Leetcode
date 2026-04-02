class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int len = s1.size();
        vector<vector<int>> even(2, vector<int>(26, 0));
        vector<vector<int>> odd(2, vector<int>(26, 0));

        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                even[0][s1[i]-'a']++;
                even[1][s2[i]-'a']++;
            } else {
                odd[0][s1[i]-'a']++;
                odd[1][s2[i]-'a']++;
            }
        }

        return even[0] == even[1] && odd[0] == odd[1];
    }
};
