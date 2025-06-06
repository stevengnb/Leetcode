class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisible = 0;
        int nDivisible = 0;

        for(int i = 1; i <= n; i++) {
            if(i % m == 0) divisible += i;
            else nDivisible += i;
        }

        return nDivisible - divisible;
    }
};