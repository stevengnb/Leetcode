class Solution {
public:

    vector<int> lexicalOrder(int n) {
        vector<int> vect;
        int counter = 0;
        int temp = 1;

        while(counter < n) {
            vect.push_back(temp);
            counter++;

            if(temp * 10 <= n) {
                temp *= 10;
            } else {
                while (temp >= n || temp % 10 == 9) {
                    temp /= 10;
                }
                temp++;
            }
        }

        return vect;
    }
};