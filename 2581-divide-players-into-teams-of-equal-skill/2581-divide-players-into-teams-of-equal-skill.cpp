class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0;
        int target;
        int len = skill.size();
        long long end = 0;

        for(int i : skill) sum += i;
        target = sum / (len/2);

        sort(skill.begin(), skill.end());

        for(int i = 0; i < len/2; i++) {
            if(skill[i] + skill[len-i-1] == target) {
                end += skill[i] * skill[len-i-1];
            } else {
                return -1;
            }
        }

        return end;
    }
};