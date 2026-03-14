class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        unordered_map<int, int> map;
        int idx = -1;

        for (int i = 0; i < matrix.size(); i++) {
            int min = 100001;
            idx = -1;

            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                    idx = j;
                }
            }
            
            if(map[idx] == 0) {
                map[idx] = min;
            } else {
                if (min > map[idx]) map[idx] = min;
            }
        }

        for (auto a : map) {
            bool biggest = true;
            for (int i = 0; i < matrix.size(); i++) {
                if (a.second < matrix[i][a.first]) {
                    biggest = false;
                    break;
                }
            }
            if (biggest) ans.push_back(a.second);
        }

        return ans;
    }
};