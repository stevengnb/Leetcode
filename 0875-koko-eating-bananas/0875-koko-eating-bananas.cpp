class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = INT_MIN;
        int ans = 0;
        float res = 0;
        
        for(int i : piles) {
            if(i > max) max = i;
        }

        int left = 0;
        int right = max;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            int totalHours = 0;

            if(mid == 0) break;

            for(double i : piles) {
                res = ceil((double)i/(double)mid);
                totalHours += res;
            }

            if(totalHours <= h) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }

        return ans;
    }
};