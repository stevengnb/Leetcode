class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowelsBit{
            {'a', 1},
            {'e', 2},
            {'i', 4},
            {'o', 8},
            {'u', 16}
        };

        vector<int> maskData(32, -1);
        int result = 0, mask = 0;

        for(int i = 0; i < s.length(); i++) {
            if(vowelsBit.find(s[i]) != vowelsBit.end()) mask = mask ^ vowelsBit[s[i]];
            if(maskData[mask] != -1 || mask == 0) {
                int len = i - maskData[mask];
                result = max(result, len);
            } else {
                maskData[mask] = i;
            }
        }

        return result;
    }
};