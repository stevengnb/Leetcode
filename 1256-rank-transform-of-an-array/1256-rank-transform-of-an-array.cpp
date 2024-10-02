class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> vect = arr;
        vector<int> ans;
        unordered_map<int, int> map;

        sort(arr.begin(), arr.end());

        int count = 1;
        for(int i = 0; i < arr.size(); i++) {
           if(map.find(arr[i]) == map.end()) {
            map.insert({arr[i], count++});
           }
        }

        for(int i : vect) {
            ans.push_back(map[i]);
        }

        return ans;
    }
};