class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum = 0;
        int n = nums.size();
        vector<long long int> prefixSum(n, 0);

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            prefixSum[i] = sum;
        }

        sum = 0;
        for(int i = 0; i < n - 1; i++) if(prefixSum[i] >= prefixSum[n-1] - prefixSum[i]) sum++;

        return sum;
    }
};