class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                if(x == c) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};