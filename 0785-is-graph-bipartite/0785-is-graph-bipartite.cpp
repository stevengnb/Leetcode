class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vect(graph.size()+1, -1);
        queue<int> que;

        for (int i = 0; i < graph.size(); i++) {
            if (vect[i] == -1) que.push(i);
            
            while (!que.empty()) {
                int front = que.front();
                if (vect[front] == -1) vect[front] = 0;

                for (int i = 0; i < graph[front].size(); i++) {
                    int curr = graph[front][i];
                    if (vect[curr] == -1) {
                        // blm visited
                        vect[curr] = !vect[front];
                        que.push(curr);
                    } else if (vect[curr] == vect[front]) return false;
                }
                que.pop();
            }
        }

        return true;
    }
};