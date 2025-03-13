class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int min = 0;
        int pos = 0;

        for(int i : nums) {
            if(i < 0) min++;
            else if(i > 0) pos++;
        }

        return max(min, pos);
    }
};