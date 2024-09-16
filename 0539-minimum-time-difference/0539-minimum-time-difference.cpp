class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vect;
        int min = INT_MAX;

        for(int i = 0; i < timePoints.size(); i++) {
            int hour = stoi(timePoints[i].substr(0, 2));
            int minute = stoi(timePoints[i].substr(3)); 
            vect.push_back(hour*60 + minute);
        }

        sort(vect.begin(), vect.end()); 

        for(int i = 0; i < vect.size()-1; i++) {
            if(abs(vect[i+1] - vect[i]) < min) {
                min = abs(vect[i+1] - vect[i]);

                if(min == 0) break;
            }
        }

        int last = 24 * 60 - abs(vect[vect.size()-1] - vect[0]);
        if(last < min) return last;

        return min;
    }
};