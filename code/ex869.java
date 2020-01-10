class Solution {
    public boolean reorderedPowerOf2(int N) {
        String nstr = String.valueOf(N);
        int[] cnt = new int[10];
        for (char c : nstr.toCharArray())    cnt[c - '0']++;
        
        List<String> cand = getCandidates(nstr.length());
        for (String can : cand) {    // O(1)
            int[] canCnt = new int[10];
            for (char c : can.toCharArray())    canCnt[c - '0']++;
            boolean match = true;
            for (int i = 0; i < 10; i++) {    // O(1)
                if (cnt[i] != canCnt[i]) {
                    match = false;
                    break;
                }
            }
            if (match)    return true;
        }
        
        return false;
    }
    
    private List<String> getCandidates(int digits) {    // O(1)
        List<String> cand = new ArrayList<>();
        int i = 0;
        while (true) {
            String can = String.valueOf((int)Math.pow(2, i));
            if (can.length() > digits)    break;
            if (can.length() == digits)    cand.add(can);
            i++;
        }
        return cand;
    }
}