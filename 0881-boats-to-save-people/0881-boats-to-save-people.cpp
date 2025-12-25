class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0;
        int right = people.size() - 1;
        int counter = 0;

        while (left <= right) {
            int leftVal = people[left];
            int rightVal = people[right];

            if (leftVal + rightVal > limit) {
                counter++;
            } else {
                counter++;
                left++;    
            }
            right--;
        }

        return counter;
    }
};