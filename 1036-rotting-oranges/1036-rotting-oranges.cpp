class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int maxMinute = 0, i, j, minute;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i, j), maxMinute));
                }
            }
        }

        while(!q.empty()) {
            pair<pair<int, int>, int> orange = q.front();
            q.pop();
            i = orange.first.first;
            j = orange.first.second;
            minute = orange.second;
            maxMinute = max(maxMinute, minute);

            if(i - 1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                q.push(make_pair(make_pair(i-1, j), minute + 1));
            }

            if(i + 1 < grid.size() && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                q.push(make_pair(make_pair(i+1, j), minute + 1));
            }

            if(j - 1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                q.push(make_pair(make_pair(i, j-1), minute + 1));
            }

            if(j + 1 < grid[0].size() && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                q.push(make_pair(make_pair(i, j+1), minute + 1));
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    maxMinute = -1;
                    break;
                }
            }
        }
        
        return maxMinute;
    }
};