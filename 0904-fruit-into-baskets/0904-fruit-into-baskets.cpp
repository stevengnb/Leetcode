class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int type = 0;
        int totalFr = 0;
        unordered_map<int, int> map;

        for (int right = 0; right < fruits.size(); right++) {
            if (map[fruits[right]] == 0) type++;
            map[fruits[right]] += 1;
            
            while (type > 2) {
                map[fruits[left]] -= 1;
                if (map[fruits[left]] == 0) type--;
                left++;
            }

            totalFr = max(totalFr, right - left + 1);
        }

        return totalFr;
    }
};