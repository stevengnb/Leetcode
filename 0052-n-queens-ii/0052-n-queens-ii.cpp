class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> path(n, string(n, '.'));

        backtrack(ans, path, 0, 0, n);

        return ans;
    }

    void backtrack(int &ans, vector<string> &path, int x, int y, int n) {
        if (x == n) {
            ans++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isValid(x, j, path, n)) {
                path[x][j] = 'Q';
                backtrack(ans, path, x+1, y, n);
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