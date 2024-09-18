class Solution {
public:
    static bool compareFunc(string a, string b) {
        if(a+b > b+a) return true;
        else return false;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> vect;
        long long int total = 0;

        for(int a : nums) {
            vect.push_back(to_string(a));
            total += a;
        }

        if(total == 0) return "0";
        sort(vect.begin(), vect.end(), compareFunc);
        
        string answer = "";
        for(string s : vect) {
            answer += s;
        }

        return answer;
    }
};