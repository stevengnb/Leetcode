class Solution {
public:
    unordered_map<string, int> map;

    void simple_tokenizer(string s) {
        stringstream ss(s);
        string word;
        while (ss >> word) {
            map[word]++;
        }
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> vect;

        simple_tokenizer(s1);
        simple_tokenizer(s2);

        for(auto& m : map) {
            if(m.second == 1) vect.push_back(m.first);
        }

        return vect;
    }
};