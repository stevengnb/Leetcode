class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum = 0;
        double maxAvg = 0.0;

        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        maxAvg = (double)sum/k;

        for(int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxAvg = max(maxAvg, (double)sum/k);
        }

        return maxAvg;
    }
};