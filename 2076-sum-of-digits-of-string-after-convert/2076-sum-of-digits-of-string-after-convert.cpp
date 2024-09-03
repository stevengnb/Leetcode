class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;

        for(int i = 0; i < s.size(); i++) {
            int curr = (int)s[i] - 96;
            sum += curr/10;
            sum += curr%10;
        }

        for(int i = 0; i < k - 1; i++) {
            string s = to_string(sum);
            int len = s.length();
            sum = 0;
            for(int j = 0; j < len; j++) {
                sum += int(s[j] - '0');
            }
        }

        return sum;
    }
};