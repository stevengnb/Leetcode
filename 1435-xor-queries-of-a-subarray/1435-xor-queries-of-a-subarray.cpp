class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<int> vect(queries.size(), -1);
        vector<int> prefix(size + 1, 0);

        for(int i = 1; i <= size; i++) {
            prefix[i] = prefix[i-1] ^ arr[i-1];
        }

        for(int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            vect[i] = prefix[left] ^ prefix[right+1];
        }

        return vect;
    }
};