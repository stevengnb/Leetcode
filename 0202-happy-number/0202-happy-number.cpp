class Solution {
public:
    bool isHappy(int n) {
        int total = 0;
        
        while(n != 0) {
            // cout << "total = " << total << endl;
            // cout << "n = " << n << ", n%10 = " << n % 10 << ", pow = " << pow(n % 10, 2) << endl << endl;
            total += pow(n % 10, 2);
            n /= 10;

            if (n == 0 && total < 10) {
               break;
            } else if(n == 0) {
                n = total;
                total = 0;
            }
        }

        if(total == 1 || total == 7) return true;
        else return false;


        // 4 -> 16
        // 1^2 + 6^2 = 37
        // 9 + 49 = 58
        // 25 + 64 = 89
        // 64 + 81 = 145
        // 42
        // 20
        // 4
    }
};