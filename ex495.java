class Solution {
    public int findPoisonedDuration(int[] time, int duration) {
        int n = time.length;
        if (n == 0)    return 0;
        
        int len = 0;
        for (int i = 1; i < n; i++) {
            if (time[i] - time[i - 1] >= duration)    len += duration;
            else    len += (time[i] - time[i - 1]);
        }
        
        return len + duration;
    }
}