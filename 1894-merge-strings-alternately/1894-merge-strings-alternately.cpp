class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        int len1 = word1.size();
        int len2 = word2.size();

        int len = len1 < len2 ? len1 : len2;
        int i; 

        for(i = 0; i < len; i++) {
            ans += word1[i];
            ans += word2[i];
        }

        if(len1 > len2) {
            ans += word1.substr(i, len1 - len2);
        } else if(len2 > len1) {
            ans += word2.substr(i, len1 - len2);    
        }
        
        return ans;
    }
};