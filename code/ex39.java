class Solution {
    public int n;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        n = candidates.length;
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        dfs(res, path, candidates, target, 0);
        return res;
    }
    
    private void dfs(List<List<Integer>> res, List<Integer> path, int[] candidates, int target, int s) {
        if (target < 0)    return;
        if (target == 0) {
            res.add(new ArrayList<Integer>(path));
        }
        
        for (int i = s; i < n; i++) {
            if (candidates[i] > target)    continue;
            path.add(candidates[i]);
            dfs(res, path, candidates, target - candidates[i], i);
            path.remove(path.size() - 1);
        }
    }
}