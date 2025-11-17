class Solution {
public:
    int numSub(string s) {
        
        long long num = 0;
        int count = 0;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            if (s[i] == '1') count++;
            if (s[i] == '0' || i == len-1) {
                num += show(count);
                count = 0;
            }
        }

        return num % 1000000007;
    }

    long long show(long x) {
        return x * (x+1) / 2; 
    }
};