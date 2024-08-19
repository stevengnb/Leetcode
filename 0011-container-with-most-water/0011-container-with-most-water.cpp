class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max = -9999;
        int luas = 0;

        while(left < right) {
            luas = (right - left) * min(height[right], height[left]);
            if(luas > max) max = luas;
            if(height[right] > height[left]) left++;
            else right--;
        }

    return max;
    }
};