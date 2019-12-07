// O(1)

class HitCounter {
    private int[] hit;    // Record the number of hits on that timestamp
    private int[] ts;    // Record the actual timestamp on that position

    /** Initialize your data structure here. */
    public HitCounter() {
        hit = new int[300];
        ts = new int[300];
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    public void hit(int timestamp) {
        if (ts[timestamp % 300] == timestamp) {
            hit[timestamp % 300]++;
        } else {
            ts[timestamp % 300] = timestamp;
            hit[timestamp % 300] = 1;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < 300; i++)
            if (timestamp - ts[i] < 300)
                total += hit[i];
        return total;
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */