class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() <= 0) return true;
        unordered_map<int, vector<int>> map;
        vector<int> state(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            map[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (auto m : map) {
            if (dfs(map, state, m.first)) return false;
        }

        return true;
    }

    bool dfs (unordered_map<int, vector<int>>& vect, vector<int>& state, int idx) {
        if (state[idx] == 1) return true;
        if (state[idx] == 2) return false;
        state[idx] = 1;

        for (int i = 0; i < vect[idx].size(); i++) {
            if (dfs(vect, state, vect[idx][i])) return true;
        }

        state[idx] = 2;
        return false;
    }
};