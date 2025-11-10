class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> que;
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> arr(mat.size(), vector<int>(mat[0].size(), 0));

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) que.push(make_pair(i, j));
            }
        }

        while (!que.empty()) {
            auto p = que.front();
            int first = p.first;
            int second = p.second;
            arr[first][second] = 1;
            
            if (first - 1 >= 0 && arr[first-1][second] == 0 && mat[first-1][second] != 0) {
                ans[first-1][second] = mat[first-1][second] + ans[first][second];
                arr[first-1][second] = 1;
                que.push(make_pair(first-1, second));
            }

            if (first + 1 < mat.size() && arr[first+1][second] == 0 && mat[first+1][second] != 0) {
                ans[first+1][second] = mat[first+1][second] + ans[first][second];
                arr[first+1][second] = 1;
                que.push(make_pair(first+1, second));
            }

            if (second - 1 >= 0 && arr[first][second-1] == 0 && mat[first][second-1] != 0) {
                ans[first][second-1] = mat[first][second-1] + ans[first][second];
                arr[first][second-1] = 1;
                que.push(make_pair(first, second-1));
            }

            if (second + 1 < mat[0].size() && arr[first][second+1] == 0 && mat[first][second+1] != 0) {
                ans[first][second+1] = mat[first][second+1] + ans[first][second];
                arr[first][second+1] = 1;
                que.push(make_pair(first, second+1));
            }

            que.pop();
        }

        return ans;
    }
};