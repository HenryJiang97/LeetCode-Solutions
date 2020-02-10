class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> cur = new ArrayList<>();
    
    public List<List<Integer>> getFactors(int n) {
        if (n == 1)    return res;
        backtracking(n, 1);
        return res;
    }
    
    private void backtracking(int n, int num) {
        if (num == n) {
            res.add(new ArrayList<>(cur));
            return;
        }
        
        int i = cur.size() > 0 ? cur.get(cur.size() - 1) : 2;
        for ( ; i <= Math.min(n / 2, n / num); i++) {
            int newNum = num * i;
            if (n % newNum != 0 || newNum > n)    continue;
            cur.add(i);
            backtracking(n, newNum);
            cur.remove(cur.size() - 1);
        }
    }
}