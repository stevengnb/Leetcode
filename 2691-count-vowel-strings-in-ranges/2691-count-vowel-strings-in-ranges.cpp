class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        /*
            0 - 1
            1 - 1
            2 - 2
            3 - 3
            4 - 4

            0 - 1
            1 - 2
            2 - 3
        */
        
        vector<int> prefixSum(words.size(), 0);
        vector<int> ans(queries.size(), 0);
        int sum = 0;

        for(int i = 0; i < words.size(); i++) {
            if(vowel(words[i])) sum++;
            prefixSum[i] += sum;
        }

        for(int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if(start == end) {
                if(start == 0 && vowel(words[start])) ans[i] = 1;
                else {
                    if(start != 0 && prefixSum[start] - prefixSum[start-1] > 0) ans[i] = 1;
                    else ans[i] = 0;
                }
            } else if(start == 0) {
                ans[i] = prefixSum[end];
            } else {
                ans[i] = prefixSum[end] - prefixSum[start-1];
            }
        }

        // cout << "PREFIX SUM (" << prefixSum.size() << ")" << endl;
        // for(int i = 0; i < prefixSum.size(); i++) {
        //     cout << "idx = " << i << ", ps = " << prefixSum[i] << endl;
        // }

        return ans;
    }

    bool vowel(const string& s) {
        if (s.empty()) return false;

        string vowels = "aeiou";
        char first = s.front();
        char last = s.back();

        return vowels.find(first) != string::npos && vowels.find(last) != string::npos;
    }
};