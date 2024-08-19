class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        int idx = 0;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[mid][0] <= target && target <= matrix[mid][matrix[mid].size()-1]) {
                idx = mid;
                break;
            } else if(matrix[mid][0] > target) {
                right = mid - 1;
            } else left = mid + 1;
        }

        left = 0;
        right = matrix[idx].size()-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[idx][mid] == target) return true;
            else if(matrix[idx][mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};