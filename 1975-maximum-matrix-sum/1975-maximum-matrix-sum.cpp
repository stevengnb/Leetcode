class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int numOfNegative = 0;
        int lowestAbs = INT_MAX;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                sum += abs(matrix[i][j]);
                if (abs(matrix[i][j]) < lowestAbs) lowestAbs = abs(matrix[i][j]);
                if (matrix[i][j] < 0) numOfNegative++;
            }
        }

        if (numOfNegative % 2 == 0) return sum;
        return sum - 2 * lowestAbs;
    }
};