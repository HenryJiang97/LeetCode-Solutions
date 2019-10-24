// Binary Search

class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        
        int res = 0;
        for (int house : houses) {
            int dis = distToClosestHeater(heaters, house);
            // System.out.println(dis);
            res = Math.max(res, dis);
        }
        
        return res;
    }
    
    private int distToClosestHeater(int[] heaters, int target) {
        int lo = 0, hi = heaters.length - 1;
        
        int min = Integer.MAX_VALUE;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            min = Math.min(min, Math.abs(heaters[mid] - target));
            
            if (heaters[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return min;
    }
}