class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path(n, string(n, '.'));

        backtrack(ans, path, 0, 0, n, 0);

        return ans;
    }

    void backtrack(vector<vector<string>> &ans, vector<string> &path, int x, int y, int n, int queen) {
        if (queen == n) {
            ans.push_back(path);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isValid(x, j, path, n)) {
                path[x][j] = 'Q';
                backtrack(ans, path, x+1, y, n, queen+1);
                path[x][j] = '.';
            }
        }
    }

    bool isValid(int x, int y, vector<string> &path, int n) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < n; j++) {
                if (path[i][j] == 'Q') {
                    if (i == x || j == y) return false;
                    else if (abs(i-x) == abs(j-y)) return false;
                }
            }
        }
        return true;
    }
};