class TimeMap {
    unordered_map<string,vector<pair<string, int>>> data;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back(make_pair(value, timestamp));
    }

    string get(string key, int timestamp) {
        const auto& vect = data[key];
        
        if(vect.size() == 0) return "";

        int left = 0;
        int right = vect.size()-1;
        string r = "";

        while(left <= right) {
            int mid = left + (right-left)/2;

            if(vect[mid].second == timestamp) return vect[mid].first;
            else if(vect[mid].second < timestamp) {
                r = vect[mid].first;
                left = mid + 1;
            } 
            else right = mid - 1;
        }


        return r;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */