class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        double sum = 0;
        double maxAverg = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (i - left + 1 > k) {
                sum -= nums[left];
                left++;
            }

            if (i - left + 1 == k) {
                maxAverg = max(maxAverg, sum/k);
            }
        }

        return maxAverg;
    }
};