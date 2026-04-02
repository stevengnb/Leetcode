class Solution {
public:
    bool isSame(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) return false;
        return true;
    }

    bool checkStrings(string s1, string s2) {
        int len = s1.size();
        string news1;
        string news2;

        for (int i = 0; i < len; i += 2) {
            news1 += s1[i];
            news2 += s2[i];
        }

        sort(news1.begin(), news1.end());
        sort(news2.begin(), news2.end());
        if (!isSame(news1, news2)) return false;

        news1 = news2 = "";
        
        for (int i = 1; i < len; i+= 2) {
            news1 += s1[i];
            news2 += s2[i];
        }

        sort(news1.begin(), news1.end());
        sort(news2.begin(), news2.end());

        return isSame(news1, news2);

        /*
        ANSWER 2 (750/752)

        int len = s1.size();
        unordered_map<char, int> mapEven;
        unordered_map<char, int> mapOdd;

        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                mapEven[s1[i]]++;
                mapEven[s2[i]]++;
            } else {
                mapOdd[s1[i]]++;
                mapOdd[s2[i]]++;
            }
        }

        for (auto val : mapEven) if (val.second % 2 == 1) return false;
        for (auto val : mapOdd) if (val.second % 2 == 1) return false;
        // cout << "key in even = " << val.first << " is " << val.second << endl;
        // cout << "key in odd = " << val.first << " is " << val.second << endl;
        // cout << endl;
        return true;

        */



        /*
            s1 = a b c d b a
            s2 = c a b d a b

            s1 = a c b, b d a
            s2 = c b a, a d b

        */

        // ANSWER 1
        // for (int i = 0; i < len-2; i++) {
        //     if (s1[i] == s2[i]) continue;
        //     bool flag = false;

        //     for (int j = i+2; j < len; j+=2) {
        //         if (s1[j] == s2[i]) {
        //             // ketemu yg sama
        //             int temp = s1[j];
        //             s1[j] = s1[i];
        //             s1[i] = temp;
        //             flag = true;
        //             break;
        //         }
        //     }

        //     if (!flag) return false;
        // }
        
        // if (len < 2) {
        //     for (int i = 0; i < len; i++) if (s1[i] != s2[i]) return false;
        // } else {
        //     for (int i = len-2; i < len; i++) if (s1[i] != s2[i]) return false;
        // }
        // return true;
    }
};
