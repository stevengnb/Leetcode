class MyCalendar {
public:
    set<pair<int, int>> set;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto lwr = set.lower_bound({start, end});

        // lwr itu ambil element pertama yg >= start
        // kalau lwr bukan di akhir, cek apakah end > lwr first
        if(lwr != set.end() && lwr->first < end) {
            return false;
        }

        // kalau lwr bukan di awal, cek prevnya apakah prev second > start
        if(lwr != set.begin()) {
            auto prevLwr = prev(lwr);
            if(prevLwr->second > start) {
                return false;
            }
        }

        // kalau setnya kosong, set.begin() sama set.end() sama" ngarah pointer ke end of iterator, jadi lower boundnya bakal selalu == set.begin() == set.end()
        set.insert({start, end});
        return true;
    }
};
