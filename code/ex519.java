class Solution {
    public Set<Integer> flipped;
    public int m, n;
    public Random rand;
    
    public Solution(int n_rows, int n_cols) {
        m = n_rows;    n = n_cols;
        flipped = new HashSet<>();
        rand = new Random();
    }
    
    public int[] flip() {
        int randi = rand.nextInt(m), randj = rand.nextInt(n);
        while (flipped.contains(randi * n + randj)) {
            randi = rand.nextInt(m);    randj = rand.nextInt(n);
        }
        flipped.add(randi * n + randj);
        return new int[]{randi, randj};
    }
    
    public void reset() {
        flipped = new HashSet<>();
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */