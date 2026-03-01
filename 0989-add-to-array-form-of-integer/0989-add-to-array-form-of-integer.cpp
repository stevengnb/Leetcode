class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        int temp = 0;
        int len = num.size();
        vector<int> ans = num;

        for (int i = len-1; i >= 0; i--) {
            int digit = k % 10;
            k /= 10;

            int res = ans[i] + digit + temp;

            ans[i] = res % 10;
            temp = res / 10;
            cout << endl;
        }

        while (temp > 0 || k > 0) {
            int digit = k % 10;
            k /= 10;

            int res = digit + temp;
            ans.insert(ans.begin(), res % 10);

            temp = res / 10;
        }

        return ans;
    }
};