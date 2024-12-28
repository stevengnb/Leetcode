class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1 && flowerbed[0] == 0) {
            n--;
        }
        int idx = 0;
        int i = 0;

        while(i < flowerbed.size() && n > 0) {
            cout << " flowered i = " << flowerbed[i] << ", n = " << n << endl;
            if(i == 0) {
                if(flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--; 
                }
            } else if(i == flowerbed.size() - 1) {
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            } else {
                if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            } 
            i++;
        }

        if(n > 0) return false;

        return true;
    }
};