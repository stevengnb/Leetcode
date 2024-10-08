class Solution {
public:
    int minLength(string s) {
        stack<char> stackk;
        stackk.push(s[0]);

        for(int i = 1; i < s.length(); i++) {
            if(stackk.empty()) {
                stackk.push(s[i]);
                continue;
            }

            if(stackk.top() == 'A' && s[i] == 'B') {
                stackk.pop();
            } else if(stackk.top() == 'C' && s[i] == 'D') {
                stackk.pop();
            } else {
                stackk.push(s[i]);
            }
        }

        return stackk.size();
    }
};