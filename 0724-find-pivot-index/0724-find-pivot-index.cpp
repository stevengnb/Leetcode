class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumAll = 0;
        vector<int> sum = {0};

        for(int i : nums) {
            sumAll += i;
            sum.push_back(sumAll);
        }

        for(int i = 0; i < sum.size() - 1; i++) {
            if(sum[i+1] - sum[0] == sum[sum.size()-1] - sum[i]) return i;
        }

        return -1;
    }
};