class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<int>> set;
        int max, i = 0, iBreak = 3;

        for(int num : nums) {
            set.insert(num);
        }

        if(set.size() < 3) iBreak = 1;

        for(int num : set) {
            if(i == iBreak) break;
            max = num;
            i++;
        }

        return max;
    }
};