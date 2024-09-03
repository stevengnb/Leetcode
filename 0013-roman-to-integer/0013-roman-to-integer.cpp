class Solution {
public:
    int romanToInt(string s) {
        int sum = 0, idx = 0;
        int len = s.length();

        unordered_map<char, int> map = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000},
        };

        while(idx < len) {
            if(map[s[idx]] < map[s[idx+1]] && idx < len-1) {
                sum += map[s[idx+1]] - map[s[idx]];
                idx++;
            } else {
                sum += map[s[idx]];
            }

            idx++;
        }

        return sum;
    }
};