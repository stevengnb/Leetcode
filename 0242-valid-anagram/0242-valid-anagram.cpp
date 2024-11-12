class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<int, int> mapS;
        unordered_map<int, int> mapT;

        for(int i = 0; i < s.length(); i++) {
            mapS[int(s[i] - 'a')]++;
            mapT[int(t[i] - 'a')]++;
        }

        for(int i = 0; i < 26; i++) {
            if(mapS[i] != mapT[i]) return false;
        }

        return true;
    }
};