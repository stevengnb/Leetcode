class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for (string operation : operations) {
            char first = operation[0];
            char last = operation[operation.size()-1];

            if (first == '+' || last == '+') { x++; continue; }
            else if (first == '-' || last == '-') x--;
        }

        return x;
    }
};