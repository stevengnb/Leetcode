class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            set<char> set; 
            int currentLength = 0;

            for(int j = i; j < n; j++) {
                if(set.find(s[j]) != set.end()) {
                    break;
                } else {
                    set.insert(s[j]);
                    currentLength++;
                }
            }

            maxLength = max(maxLength, currentLength);
            if (n - i <= maxLength) break;
        }

        return maxLength;
    }
};