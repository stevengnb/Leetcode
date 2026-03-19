class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> map;

        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < edges[0].size(); j++) {
                map[edges[i][j]]++;
                if (map[edges[i][j]] == edges.size()) return edges[i][j];
            }
        }

        return -1;
    }
};