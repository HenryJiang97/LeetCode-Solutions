class Solution {
    private int n;
    private List<List<Integer>> res = new ArrayList<>();
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        n = candidates.length;
        List<Integer> cur = new ArrayList<>();
        boolean[] visited = new boolean[n];
        backtracking(candidates, cur, visited, 0, 0, target);
        return res;
    }
    
    private void backtracking(int[] candidates, List<Integer> cur, boolean[] visited, int s, int sum, int target) {
        if (sum == target) {
            res.add(new ArrayList<>(cur));
            return;
        }
        if (s >= n || sum > target)    return;
        
        for (int i = s; i < n; i++) {
            if (visited[i])    continue;
            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1])    continue;
            cur.add(candidates[i]);
            visited[i] = true;
            backtracking(candidates, cur, visited, i + 1, sum + candidates[i], target);
            visited[i] = false;
            cur.remove(cur.size() - 1);
        }
    }
}