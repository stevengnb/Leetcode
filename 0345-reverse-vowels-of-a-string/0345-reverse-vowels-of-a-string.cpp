class Solution {
public:
    string reverseVowels(string s) {
        vector<pair<int, char>> charc;

        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) {
                charc.push_back(make_pair(i, s[i]));
            }
        }
        
        int idx = 0;

        for(int i = charc.size() - 1; i >= 0; i--) {
            s[charc[idx++].first] = charc[i].second;
        }

        return s;
    }

    bool isVowel(char c) {
        if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
        c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            return true;
        } else {
            return false;
        }
    }
};