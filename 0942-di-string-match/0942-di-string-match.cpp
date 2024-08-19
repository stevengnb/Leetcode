class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> vect;
        int max = s.length();
        int min = 0;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'I') vect.push_back(min++);
            else vect.push_back(max--);
        }

        vect.push_back(min);

        return vect;
    }
};