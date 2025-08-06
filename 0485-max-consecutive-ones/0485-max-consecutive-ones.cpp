class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxVal = 0;
        int curr = 0;

        for(int i : nums) {
            if(i == 1) {
                curr++;
                maxVal = max(curr, maxVal);
            } else {
                curr = 0;
            }
        }

        return maxVal;
    }
};