class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        int n = piles.length;
        
        int lo = 1, hi = (int)1e9;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (ifCanEat(piles, mid, H)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return hi;
    }
    
    private boolean ifCanEat(int[] piles, int speed, int hour) {
        int cnt = 0;
        for (int pile : piles) {
            cnt += Math.ceil((double)pile / speed);
        }
        return cnt <= hour;
    }
}