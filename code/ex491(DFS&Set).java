// Brute force DFS using set

class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> res = new HashSet<>();
        List<Integer> vec = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            vec.add(nums[i]);
            dfs(nums, res, vec, i + 1);
            vec.remove(vec.size() - 1);
        }
        
        List<List<Integer>> list = new ArrayList<>();
        for (List<Integer> r : res)
            list.add(r);
        
        return list;
    }
    
    private void dfs(int[] nums, Set<List<Integer>> res, List<Integer> vec, int start) {
        for (int i = start; i < nums.length; i++) {
            if (vec.size() > 0 && nums[i] >= vec.get(vec.size() - 1)) {
                vec.add(nums[i]);
                res.add(new ArrayList<Integer>(vec));
                dfs(nums, res, vec, i + 1);
                vec.remove(vec.size() - 1);
            } else {
                dfs(nums, res, vec, i + 1);
            }
        }
    }
}