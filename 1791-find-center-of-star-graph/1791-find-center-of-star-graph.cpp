class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int array[100001] = {0};

        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            array[edge[0]]++;
            if (array[edge[0]] == edges.size()) return edge[0]; 

            array[edge[1]]++;
            if (array[edge[1]] == edges.size()) return edge[1]; 
        }

        return -1;
    }
};