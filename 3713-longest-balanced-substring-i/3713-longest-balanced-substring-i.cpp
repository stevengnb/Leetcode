class Solution {
public:
    int longestBalanced(string s) {
        int maxVal = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> map;
            for (int j = i; j < s.size(); j++) {
                bool balanced = true;
                int before = -1;
                map[s[j]]++;

                for (auto a : map) {
                    if (before != -1 && a.second != before) {
                        balanced = false;
                        break;
                    }
                    before = a.second;
                }

                if (balanced) maxVal = max(maxVal, j-i+1);
            }
        }

        return maxVal;
    }
};