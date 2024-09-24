class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set;
        int maxVal = 0;

        for(int i : arr1) {
            while(i > 0) {
                set.insert(i);
                i /= 10;
            }
        }

        for(int i : arr2) {
            while(i > 0) {
                if(set.count(i) != 0) {
                    int len = to_string(i).size();
                    maxVal = max(maxVal, len);
                }
                i /= 10;
            }
        }
        
        return maxVal;
    }
};