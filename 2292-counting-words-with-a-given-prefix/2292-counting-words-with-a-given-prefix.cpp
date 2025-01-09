class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int counter = 0;

        for(string s : words) {
            if(s.starts_with(pref)) counter++;
        }

        return counter;
    }
};