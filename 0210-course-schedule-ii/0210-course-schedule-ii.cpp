class Solution {
public:
    vector<int> ans;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() <= 0) {
            if (numCourses <= 0) return vector<int>(1, 0);
            else {
                for (int i = numCourses - 1; i >= 0; i--) ans.push_back(i);
                return ans;
            }
        }
        unordered_map<int, vector<int>> map;
        vector<int> state(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            map[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (dfs(map, state, i)) return {};
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool dfs (unordered_map<int, vector<int>>& vect, vector<int>& state, int idx) {
        if (state[idx] == 1) return true;
        if (state[idx] == 2) {
            return false;
        }
        state[idx] = 1;

        for (int i = 0; i < vect[idx].size(); i++) {
            if (dfs(vect, state, vect[idx][i])) return true;
        }

        state[idx] = 2;
        ans.push_back(idx);
        return false;
    }
};