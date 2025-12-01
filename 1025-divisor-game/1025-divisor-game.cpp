class Solution {
public:
    bool divisorGame(int n) {
        // 1 = false
        // 2 = 0 < x < 2 true -> 1
        // 3 = 0 < x < 3 (0, 1) false -> 1
        // 4 = 0 < x < 4 (1, 2, 3) true -> 3 (n-x = 4-1) 
        // 5 = 0 < x < 5 (1, 2, 3, 4) false -> 4 (n-x = 5-1)
        // 6 = 0 < x < 6 (1, 2, 3, 4, 5) true -> 5 (n-x = 6-1)
        //

        return n % 2 == 0;
    }
};