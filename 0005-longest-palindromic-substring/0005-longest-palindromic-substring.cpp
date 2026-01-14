class Solution {
public:
    string longestPalindrome(string s) {

        int left = 0, right = 0, lp = 0, rp = 0;
        int maxVal = INT_MIN;

        for (int i = 0; i < s.size(); i++) {
            // cout << "i = " << i << ", s[i] = " << s[i] << ", maxval = " << maxVal << ", CHAR = " << s[i] << endl;
            left = right = i;

            while (left-1 >= 0 && right+1 < s.size() && (s[left-1] == s[right+1])) {
                // cout << "CHECK ODD = " << "left = " << left << ", right = " << right << ", maxVal = " << maxVal << endl;
                if ((right+1) - (left-1) + 1 > maxVal) {
                    maxVal = (right+1) - (left-1) + 1;
                    lp = left-1;
                    rp = right+1;
                }
                left--;
                right++;
            }

            left = i;
            right = i+1;

            if (s[left] != s[right]) {
                continue;
            }

            if (maxVal < 2) {
                maxVal = 2;
                lp = left;
                rp = right;
            }
            
            while (left-1 >= 0 && right+1 < s.size() && (s[left-1] == s[right+1])) {
                // cout << "CHECK EVEN = " << "left = " << left << ", right = " << right << ", maxVal = " << maxVal << endl;
                if ((right+1) - (left-1) + 1 > maxVal) {
                    maxVal = (right+1) - (left-1) + 1;
                    lp = left-1;
                    rp = right+1;
                }
                left--;
                right++;
            }
        }

        return s.substr(lp, rp-lp+1);
    }
};