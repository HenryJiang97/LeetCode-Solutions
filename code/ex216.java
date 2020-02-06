class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> cur = new ArrayList<>();
    
    public List<List<Integer>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return res;
    }
    
    private void backtracking(int k, int target, int s, int sum) {
        if (sum == target && cur.size() == k) {
            res.add(new ArrayList<>(cur));
            return;
        }
        if (sum > target || cur.size() >= k)    return;
        
        for (int i = s; i <= 9 && sum + i <= target ; i++) {
            cur.add(i);
            backtracking(k, target, i + 1, sum + i);
            cur.remove(cur.size() - 1);
        }
    }
}