class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return coinChange(coins, amount, coins.size());
    }

    int coinChange(vector<int>& coins, int amount, int n) {
        vector<int> total(amount + 1, 0);

        total[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < amount+1; j++) {
                if(j >= coins[i]) total[j] += total[j-coins[i]];
            }
        }

        return total[amount];
    }
};