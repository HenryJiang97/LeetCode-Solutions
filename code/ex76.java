class Solution {
    public String minWindow(String s, String t) {
        int n = s.length();
        
        // Get the count of the required characters
        int[] cnt = new int[126];
        for (char c : t.toCharArray())
            cnt[c]++;
        int num = 0;
        for (int i = 0; i < 126; i++)
            if (cnt[i] != 0)    num++;
        
        // Sliding window to find the minimum window including these characters
        int[] cntWindow = new int[126];
        Set<Character> inWindow = new HashSet();
        String res = s + " ";
        int lo = 0;
        for (int hi = 0; hi < n; hi++) {
            // Add character at hi pointer
            char chi = s.charAt(hi);
            if (cnt[chi] != 0) {
                if (++cntWindow[chi] >= cnt[chi])
                    inWindow.add(chi);
            }
            
            // Try to move lo pointer to the right
            while (inWindow.size() == num || hi - lo + 1 > res.length()) {
                if (inWindow.size() == num && s.substring(lo, hi + 1).length() < res.length())
                    res = s.substring(lo, hi + 1);
                char clo = s.charAt(lo);
                if (cnt[clo] != 0) {
                    if (--cntWindow[clo] < cnt[clo])
                        inWindow.remove(clo);
                }
                lo++;
            }
        }
        
        return res.equals(s + " ") ? "" : res;
    }
}