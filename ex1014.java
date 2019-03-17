class Solution { 
    public int shipWithinDays(int[] weights, int D) {
        int lo = 0, hi = 0;
        
        // Get the largest possible weight capacity and the smallest possible capacity
        for (int weight : weights) {
            hi += weight;
            lo = Math.max(lo, weight);
        }
        
        // Do binary search to find the capacity which meets the requirement of D
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            // Check if the mid capacity can meet the requirement
            int d = 1, wei = 0;
            for (int i = 0; i < weights.length; i++) {
                if (wei + weights[i] > mid) {
                    wei = 0;
                    d++;
                }
                wei += weights[i];
            }
            
            if (d > D)    lo = mid + 1;
            else    hi = mid;
        }
        
        return lo;
    }
}