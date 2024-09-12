class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int array[26] = {0};
        int counter = 0;

        for(int i = 0; i < allowed.length(); i++) array[allowed[i]-97]++;

        for(int i = 0; i < words.size(); i++) {
            bool consistent = false;
            int size = words[i].length();

            for(int j = 0; j < size; j++) {
                if(array[words[i][j]-97] <= 0) {
                    consistent = true;
                    break;
                }
            }

            if(!consistent) counter++;
        }

        return counter;
    }
};