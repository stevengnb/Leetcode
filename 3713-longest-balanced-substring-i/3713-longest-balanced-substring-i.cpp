class Solution {
public:
    int longestBalanced(string s) {
        int maxVal = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> map;
            int freq[27] = {0};
            for (int j = i; j < s.size(); j++) {
                bool balanced = true;
                int before = -1;
                freq[s[j]-'a']++;

                for (int i = 0; i < 26; i++) {
                    if (freq[i] == 0) continue;

                    if (before != -1 && freq[i] != before) {
                        balanced = false;
                        break;
                    }
                    before = freq[i];
                }

                if (balanced) maxVal = max(maxVal, j-i+1);
            }
        }

        return maxVal;
    }
};