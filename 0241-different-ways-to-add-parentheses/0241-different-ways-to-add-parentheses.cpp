class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return allWays(expression);
    }

    vector<int> allWays(string s) {
        vector<int> result;

        for(int i = 0; i < s.size(); i++) {
            char opt = s[i];
            if(opt == '*' || opt == '-' || opt == '+') {
                vector<int> left = allWays(s.substr(0, i));
                vector<int> right = allWays(s.substr(i + 1));

                for(int l : left) {
                    for(int r : right) {
                        switch(opt) {
                            case '+':
                                result.push_back(l+r);
                                break;
                            case '-':
                                result.push_back(l-r);
                                break;
                            case '*':
                                result.push_back(l*r);
                                break;
                        }
                    }
                }
            }
        }

        if(result.empty()) result.push_back(stoi(s));

        return result;
    }
};