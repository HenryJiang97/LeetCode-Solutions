// Binary Search

class Solution {
    public List<Integer> map = new ArrayList<>();    // Map all points inside rects to a 1D-array
    public Random rand = new Random();
    public int[][] rects;
    
    public Solution(int[][] rects) {
        this.rects = rects;
        int idx = 0;
        for (int[] rect : rects) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            idx += (x2 - x1 + 1) * (y2 - y1 + 1);
            map.add(idx);
        }
    }
    
    public int[] pick() {
        int randNum = rand.nextInt(map.get(map.size() - 1));
        
        // Binary search to find out which rect this random point is in
        int rectIdx = -1;
        int lo = 0, hi = map.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (map.get(mid) <= randNum) {
                lo = mid + 1;
            } else {
                if (mid - 1 < 0 || map.get(mid - 1) <= randNum) {
                    rectIdx = mid;
                    break;
                }
                hi = mid - 1;
            }
        }
        
        // Find the actual point in this rect
        int[] targetRect = rects[rectIdx];
        int x0 = targetRect[0], y0 = targetRect[1], p0 = rectIdx == 0 ? 0 : map.get(rectIdx - 1), p = randNum - p0;
        int length = targetRect[2] - targetRect[0] + 1, height = targetRect[3] - targetRect[1] + 1;
        return new int[]{x0 + p % length, y0 + p / length};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */