class Solution {
public:
    int binaryGap(int n) {
        int idx = 0, val = n, powVal = pow(2, idx+1);
        int maxVal = 0;
        string bin = "";

        while (powVal <= val) {
            powVal = pow(2, idx+1);
            idx++;
        }

        for (int i = idx-1; i >= 0; i--) {
            powVal = pow(2, i);

            if (val >= powVal) {
                val -= powVal;
                bin += "1";
            } else {
                bin += "0";
            }
        }

        idx = -1;

        for (int i = 0; i < bin.size(); i++) {
            if (bin[i] == '1') {
                if (idx != -1) maxVal = max(maxVal, i-idx);
                idx = i;
            }
        }

        return maxVal;
    }
};