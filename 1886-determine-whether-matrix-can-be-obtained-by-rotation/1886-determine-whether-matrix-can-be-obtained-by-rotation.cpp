class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // vector<vector<int>> copy;
        // printt(target);
        // target = rotateArray(target);
        // printt(target);

        for (int i = 0; i < 4; i++) {
            if (!isMatch(mat, target)) {
                // rotate
                target = rotateArray(target);
            } else {
                return true;
            }
        }

        return false;

        /*
            0 0 
            1 0

            1 0
            0 0 
        */

        /*
        
            1 1 0 0
            0 1 0 1
            1 0 1 0
            0 1 1 0

            // i j -> [j][n-i-1]
            // 0 0 -> [0][3]
            // 0 1 -> [1][2]
            // 

            transpose normal
            1 0 1 0
            1 1 0 1
            0 0 1 1
            0 1 0 0

            rotate 1x
            0 1 0 1
            1 0 1 1
            1 1 0 0
            0 0 1 0

            transpose 1x
            0 1 1 0
            1 0 1 0
            0 1 0 1
            1 1 0 0

            rotate 2x
            0 1 1 0
            0 1 0 1
            1 0 1 0
            0 0 1 1

            rotate 3x
            0 1 0 0
            0 0 1 1
            1 1 0 1
            1 0 1 0
        
            rotate 4x
            1 1 0 0
            0 1 0 1
            1 0 1 0
            0 1 1 0
        
        */
        // return true;
    }

    vector<vector<int>> rotateArray(vector<vector<int>>& target) {
        int rowSize = target.size();
        int columnSize = target[0].size();
        vector<vector<int>> ans(target[0].size(), vector<int>(rowSize));
        
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < columnSize; j++) {
                ans[i][j] = target[j][i];
            }
        }

        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < columnSize/2; j++) {
                int temp = ans[i][j];
                ans[i][j] = ans[i][columnSize-j-1];
                ans[i][columnSize-j-1] = temp;
            }
        }

        return ans;
    }

    void printt(vector<vector<int>>& target) {
        cout << "=== VECTOR === " << endl;
        for (int i = 0; i < target.size(); i++) {
            for (int j = 0; j < target[0].size(); j++) {
                cout << target[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isMatch(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
};