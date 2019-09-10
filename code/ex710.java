class Solution {
    public Map<Integer, Integer> reflection = new HashMap<>();
    public Random rand = new Random();
    public int frontLen;

    public Solution(int N, int[] blacklist) {
        int n = blacklist.length;
        frontLen = N - n;
        
        // Seperate [0, N) to two parts: good part & black points
        // Get the good points in the second part
        Set<Integer> set = new HashSet<>();
        for (int i = frontLen; i < N; i++)    set.add(i);
        for (int b : blacklist)    set.remove(b);

        // Reflect good points in the second list to the position of bad points in the first list
        Iterator<Integer> it = set.iterator();
        for (int b : blacklist) {
            if (b < frontLen) {
                reflection.put(b, it.next());
            }
        }
    }
    
    public int pick() {
        int r = rand.nextInt(frontLen);
        return reflection.getOrDefault(r, r);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */