class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int maxVal = 0, row = grid.size(), col = grid[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<pair<int, int>> que;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    que.push(make_pair(i, j));
                    ans[i][j] = 0;
                }
            }
        }

        if (que.size() <= 0 || que.size() == row * col) return -1;

        while (!que.empty()) {
            auto front = que.front();
            int first = front.first;
            int second = front.second;

            if (first - 1 >= 0 && ans[first-1][second] == -1) {
                ans[first-1][second] = ans[first][second] + abs(first - (first-1));
                que.push(make_pair(first-1, second));
                maxVal = max(maxVal, ans[first-1][second]);
            }

            if (first + 1 < row && ans[first+1][second] == -1) {
                ans[first+1][second] = ans[first][second] + abs(first - (first+1));
                que.push(make_pair(first+1, second));
                maxVal = max(maxVal, ans[first+1][second]);
            }

            if (second - 1 >= 0 && ans[first][second-1] == -1) {
                ans[first][second-1] = ans[first][second] + abs(second - (second-1));
                que.push(make_pair(first, second-1));
                maxVal = max(maxVal, ans[first][second-1]);
            }

            if (second + 1 < col && ans[first][second+1] == -1) {
                ans[first][second+1] = ans[first][second] + abs(second - (second+1));
                que.push(make_pair(first, second+1));
                maxVal = max(maxVal, ans[first][second+1]);

            }

            que.pop();
        }

        return maxVal;
    }

};