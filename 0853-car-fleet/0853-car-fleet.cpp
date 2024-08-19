class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        int fleets = 0;
        float before = 0;
        float time = 0;

        for(int i = 0; i < position.size(); i++) {
            car.push_back(make_pair(position[i], speed[i]));
        }

        sort(car.begin(), car.end());

        for(int i = car.size() - 1; i >= 0; i--) {
            time = ceil((float)(target - car[i].first))/(float)(car[i].second);
            
            if(i == car.size()-1) {
                fleets++;
                before = time;
                continue;
            }

            if(time > before) {
                before = time;
                fleets++;
            }
        }

        return fleets; 
    }
};