class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqS(60, 0);
        unordered_map<int, int> map; // <index, quantity>
        int left = 0;
        int currMax = INT_MAX;
        int start = -1;
        bool flag = true;

        for (int i = 0; i < t.size(); i++) {
            map[t[i] - 'A']++;
        }
        for (int right = 0; right < s.size(); right++) {
            flag = true;
            freqS[s[right] - 'A']++;
            
            for (auto m : map) {
                if (freqS[m.first] < m.second) {
                    flag = false;
                    break;
                }
            }

            while (flag) {
                if (right-left+1 <= currMax) {
                    currMax = (right-left+1);
                    start = left;
                }
                freqS[s[left] - 'A']--;
                left++;

                for (auto m : map) {
                    if (freqS[m.first] < m.second) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        return start == -1 ? "" : s.substr(start, currMax);
    }
};