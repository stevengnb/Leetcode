class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeros = 0;
        int window = 0;
        int longest = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;
            window++;

            while (zeros > k) {
                if (nums[left++] == 0) zeros--;
                window--;
            }

            longest = max(longest, window);
        }

        return longest;
    }

    // 1 1 1 0 0 0 1 1 1 1 0 (K = 2)
};