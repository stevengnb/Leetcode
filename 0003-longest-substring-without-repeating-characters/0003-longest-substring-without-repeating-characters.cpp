class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;

        for(int i = 0; i < s.length()-max; i++) {
            set<char> set = {s[i]};
            int counter = 0;
            counter++;

            for(int j = i+1; j < s.length(); j++) {
                if(set.find(s[j]) != set.end()) break;
                else {
                    set.insert(s[j]);
                    counter++;
                }
            }

            if(counter > max) max = counter;
        }

        return max;
    }
};