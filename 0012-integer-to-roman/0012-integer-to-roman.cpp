class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        unordered_map<int, string> map = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };
        int idx = nums.size()-1;
        string result = "";

        while(num != 0) {
            if(num - nums[idx] >= 0) {
                num -= nums[idx];
                result += map[nums[idx]];
            } else idx--;
        }

        return result;
    }
};