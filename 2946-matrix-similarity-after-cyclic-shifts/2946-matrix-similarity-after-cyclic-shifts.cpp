class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        return same(mat, rotate(mat, k));
    }

    vector<vector<int>> rotate(vector<vector<int>>&mat, int k) {
        vector<vector<int>> ans;
        int n = mat[0].size();
        int newK = k % n;

        for (int i = 0; i < mat.size(); i++) {
            vector<int> row;

            if (i % 2 == 0) {
                for (int j = newK; j < n; j++) row.push_back(mat[i][j]);
                for (int j = 0; j < newK; j++) row.push_back(mat[i][j]);
            } else {
                for (int j = n-newK; j < n; j++) row.push_back(mat[i][j]);
                for (int j = 0; j < n-newK; j++) row.push_back(mat[i][j]);
            }
            ans.push_back(row);
        }

        return ans;
    }

    bool same(vector<vector<int>> mat, vector<vector<int>> mat2) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] != mat2[i][j]) return false;
            }
        }

        return true;
    }
};