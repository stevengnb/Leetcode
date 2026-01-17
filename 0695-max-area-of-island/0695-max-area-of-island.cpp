class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxVal = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    maxVal = max(maxVal, dfs(grid, i, j));
                }
            }
        }

        return maxVal;
    }

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0
        || y < 0
        || x >= grid.size()
        || y >= grid[0].size()
        || grid[x][y] == 0) return 0; 

        grid[x][y] = 0;
        int top = dfs(grid, x-1, y);
        int bot = dfs(grid, x+1, y);
        int left = dfs(grid, x, y-1);
        int right = dfs(grid, x, y+1);

        return top + bot + left + right + 1;
    }
};