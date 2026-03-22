class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int idx = 0;
        int len = k;

        for (int i = 0; i < len/2; i++) {
            for (int j = y; j < y+k; j++) {
                int temp = grid[i+x][j];
                grid[i+x][j] = grid[(len+x)-idx-1][j];
                grid[(len+x)-idx-1][j] = temp;
            }
            idx++;
        }

        return grid;
    }
};