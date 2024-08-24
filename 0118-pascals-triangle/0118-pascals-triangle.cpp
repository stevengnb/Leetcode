class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vect;
        vect.push_back({1});

        for(int i = 1; i < numRows; i++) {
            vector<int> vectt;
            for(int j = 0; j <= i; j++) {
                if(j == 0) {
                    vectt.push_back(0+vect[i-1][0]);
                } else if(j == i) {
                    vectt.push_back(0+vect[i-1][i-1]);
                }else {
                    vectt.push_back(vect[i-1][j-1] + vect[i-1][j]);
                }
            }

            vect.push_back(vectt);
        }

        return vect;
    }
};