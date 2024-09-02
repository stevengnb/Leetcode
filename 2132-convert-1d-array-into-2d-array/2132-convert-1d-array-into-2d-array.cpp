class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> vect;
        if(original.size() != m * n) return vect;

        int idx = 0;
        for(int i = 0; i < m; i++) {
            vector<int> vectIn;
            for(int j = 0; j < n; j++) {
                vectIn.push_back(original[idx++]);
            }
            vect.push_back(vectIn);
        }

        return vect;
    }
};