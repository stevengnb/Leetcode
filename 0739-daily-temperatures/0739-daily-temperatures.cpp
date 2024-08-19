class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> result(temperatures.size(), 0);

        for(int i = temperatures.size() - 1; i >= 0; i--) {
            if(st.empty()) {
                result[i] = 0;
                st.push(make_pair(temperatures[i], i));
            } else {
                while(!st.empty() && st.top().first <= temperatures[i]) {
                    st.pop();
                }

                if(st.empty()) result[i] = 0;
                else result[i] = st.top().second - i;

                st.push(make_pair(temperatures[i], i));
            } 
        }

        return result;
    }
};