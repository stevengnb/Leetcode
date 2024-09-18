class Solution {
public:
    static bool compareFunc(string a, string b) {
        if(a+b > b+a) return true;
        else return false;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> vect;

        for(int a : nums) vect.push_back(to_string(a));

        sort(vect.begin(), vect.end(), compareFunc);
        if(!vect.empty() && vect[0] == "0") return "0";
        
        string answer = "";
        for(string s : vect) {
            answer += s;
        }

        return answer;
    }
};