class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int l = flowerbed.length;
        if (l == 1 && flowerbed[0] == 0) {
            return n <= 1 ? true : false;
        }
        
        int cnt = 0;
        if (flowerbed[0] == 0 && l > 1 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            cnt++;
        }
        
        for (int i = 1; i < l - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                cnt++;
                flowerbed[i] = 1;
            }
        }
        
        if (flowerbed[l - 1] == 0 && l - 2 >= 0 && flowerbed[l - 2] == 0)    cnt++;
        
        return cnt >= n ? true : false;
    }
}