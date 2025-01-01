class Solution {
public:
    int maxScore(string s) {
        int max = INT_MIN;
        int zeros = 0;
        int ones = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') ones++;
        }

        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '0') zeros++;
            else ones--;
            if(zeros + ones > max) max = zeros + ones;
        }

        return max;
    }
};