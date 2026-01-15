class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        unordered_map<int, int> freq;
        int total = 0;
        int currTotal = 0;
        int maxFreq = 0;
        // char maxChar = '';

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            while ((right-left+1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            if ((right-left+1) - maxFreq == k) {
                total = max(total, maxFreq + k);
            } else if ((right-left+1) - maxFreq < k) {
                total = max(total, (right-left+1));
            }
        }

        return total;
    }
};