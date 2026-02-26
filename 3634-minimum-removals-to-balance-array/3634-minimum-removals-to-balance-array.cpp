class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1) return 0;
        sort(nums.begin(), nums.end());
        // FORMULA = max <= min * k

        // expand ketika max <= min * k
        // shrink ketika max > min * kx

        // 4 6
        int right = 0;
        int maxVal = 0;

        for (int left = 0; left < len; left++) {
            // cout << "left = " << left << ", val = " << nums[left] << endl;
            // cout << "right = " << right << ", val = " << nums[right] << endl;
            while (nums[right] <= (long long)nums[left]*k) {
                // cout << "right didalem= " << right << ", val = " << nums[right] << endl;
                if (nums[right] <= (long long)nums[left]*k) {
                    // cout << "gamasuk sini?" << endl;
                    maxVal = max(maxVal, right-left+1);
                }
                right++;
                if (right > len - 1) break;
            }

            if (right > len - 1) break;
            cout << endl;
        }

        // cout << "max window = " << maxVal << endl;

        return len - maxVal;

        // 18 <= k * 16
    }
};