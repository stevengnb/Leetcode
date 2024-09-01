class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int res = -1, res2 = -1;

        while(left <= right) {
            int mid = left + (right-left)/2;

            if(nums[mid] == target) {
                if(mid == 0 || (mid != 0 && nums[mid-1] != nums[mid])) {
                    res = mid;
                    break;
                } else {
                    right = mid-1;
                }
            }
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        if(res == -1) return vector<int>{-1,-1};
        else if(res == nums.size()-1) return vector<int>{res,res};
        else if(res == 0 && nums[1] != nums[0]) return vector<int>{0,0};

        left = res;
        right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;

            if(nums[mid] == target) {
                if(mid == nums.size()-1 || (mid != nums.size()-1 && nums[mid+1] != nums[mid])) {
                    res2 = mid;
                    break;
                } else left = mid+1;
            }
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        return vector<int>{res,res2};
    }
};