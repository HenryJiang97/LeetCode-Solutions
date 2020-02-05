class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> cur = new ArrayList<>();
    
    public List<List<Integer>> combine(int n, int k) {
        if (k > n)    return new ArrayList<>();
        backtracking(n, k, 1);
        return res;
    }
    
    private void backtracking(int n, int k, int s) {
        if (cur.size() == k) {
            res.add(new ArrayList<>(cur));
            return;
        }
        if (s > n)    return;
        
        for (int i = s; i <= n; i++) {
            cur.add(i);
            backtracking(n, k, i + 1);
            cur.remove(cur.size() - 1);
        }
    }
}