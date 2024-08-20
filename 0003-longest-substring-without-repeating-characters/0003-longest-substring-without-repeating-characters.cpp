class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int j = 0;
        unordered_set<char> set;

        for(int i = 0; i < s.length(); i++) {
            if(set.count(s[i]) == 0) {
                set.insert(s[i]);
                if((i-j+1) > maxLength) {
                    maxLength = i-j+1;
                } 
            } else {
                while(set.count(s[i]) == 1) {
                    set.erase(s[j]);
                    j++;
                }

                set.insert(s[i]);
            }
        }

        return maxLength;
    }
};