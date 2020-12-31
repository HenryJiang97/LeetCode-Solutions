class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int N) {
        int cnt = 0, n = flowerbed.size();
        for (int i = 0; i < n; i++) {
            if (flowerbed[i] == 1 || (i > 0 && flowerbed[i - 1] == 1) || (i < n - 1 && flowerbed[i + 1] == 1))    continue;
            cnt++;
            flowerbed[i] = 1;
        }
        return cnt >= N;
    }
};