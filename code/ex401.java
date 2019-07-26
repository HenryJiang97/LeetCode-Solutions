import java.util.*;

class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> res = new ArrayList<>();
        
        int[] hour = new int[]{1, 2, 4, 8};
        int[] minute = new int[]{1, 2, 4, 8, 16, 32};
        
        backtracking(res, hour, minute, num, 0, 0, 0);
        
        return res;
    }
    
    
    public void backtracking(List<String> res, int[] hour, int[] minute, int num, int n, int h, int m) {
        if (num == n) {
            String str_m = (m < 10) ? "0" + String.valueOf(m) : String.valueOf(m);
            String r = String.valueOf(h) + ":" + str_m;
            res.add(r);
            return;
        }
        
        
        for (int i = 0; i < hour.length; i++) {
            if (h + hour[i] < 12) {
                backtracking(res, Arrays.copyOfRange(hour, i + 1, hour.length), minute, num, n + 1, h + hour[i], m);
            }
        }
        
        for (int i = 0; i < minute.length; i++) {
            if (m + minute[i] < 60) {
                backtracking(res, new int[0], Arrays.copyOfRange(minute, i + 1, minute.length), num, n + 1, h, m + minute[i]);
            }
        }
    }
}