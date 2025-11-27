class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int dp[101];
        dp[0] = 1;
        int len = s.size();
        

        for (int i = 1; i < len; i++) {
            int test = stoi(s.substr(i-1, 2));

            if (s[i+1] == '0'
                || test == 10 
                || test == 20) dp[i] = dp[i-1];
            else if (test >= 11 && test <= 26) dp[i] = dp[i-1] + (i >= 2 ? dp[i-2] : 1);
            else if ((s[i] == '0' && test > 26) || test <= 0) return 0;
            else dp[i] = dp[i-1];
        }
        

        return dp[len-1];
    }
};

// 11106

// (0) 1 = 1
// (1) 2 = 1 1, 11
// (2) 2 = 1 1 10, 11 10
// (3) 2 = 1 1 10 6, 11 10 6

// 2101522
// (0) 1 = 2
// (1) 1 = 2 10
// (2) 1 = 2 10
// (3) 1 = 2 10 1
// (4) 2 = 2 10 1 5, 2 10 15
// (5) 2 = 2 10 1 5 2, 2 10 15 2
// (6) 4 = 2 10 1 5 2 2, 2 10 15 2 2, 2 10 1 5 22, 2 10 15 22