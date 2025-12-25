class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int left = 0, right = 0;
        int sizeFirst = firstList.size();
        int sizeSec = secondList.size();

        while (left < sizeFirst && right < sizeSec) {
            if (firstList[left][0] >= secondList[right][0] && firstList[left][0] <= secondList[right][1]) {
                ans.push_back({firstList[left][0], min(firstList[left][1], secondList[right][1])});
            } else if (secondList[right][0] >= firstList[left][0] && secondList[right][0] <= firstList[left][1]) {
                ans.push_back({secondList[right][0], min(firstList[left][1], secondList[right][1])});
            }

            if (right + 1 < sizeSec && firstList[left][1] >= secondList[right+1][0]) right++;
            else if (left + 1 < sizeFirst && secondList[right][1] >= firstList[left+1][0]) left++;
            else {
                left++;
                right++;
            }
        }

        return ans;
    }
};