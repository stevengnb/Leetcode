class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        int mod = -1;
        int idx;

        for(int i : chalk) {
            sum += i;
        }

        mod = k % sum;
        if(mod == 0) return 0;

        for(int i = 0; i < chalk.size(); i++) {
            if(chalk[i] <= mod) mod -= chalk[i];
            else {
                idx = i;
                break;
            }
        }

        return idx;
    }
};