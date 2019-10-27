class Solution {
    public int sum = 0;
    
    public int pathSum(int[] nums) {        
        // Build a tree array
        int[][] tree = new int[6][17];
        for (int i = 0; i < 6; i++)    Arrays.fill(tree[i], -1);
        for (int num : nums) {
            int level = num / 100, pos = num / 10 % 10, val = num % 10;
            tree[level][pos] = val;
        }
        
        // Get sum
        dfs(tree, 1, 1, 0);
        
        return sum;
    }
    
    private void dfs(int[][] tree, int level, int pos, int curSum) {
        curSum += tree[level][pos];
        if (tree[level + 1][pos * 2 - 1] == -1 && tree[level + 1][pos * 2] == -1) {    // If leaf node, return
            sum += curSum;
            return;
        }
        
        // Go to left and right subtrees
        if (tree[level + 1][pos * 2 - 1] != -1)
            dfs(tree, level + 1, pos * 2 - 1, curSum);
        if (tree[level + 1][pos * 2] != -1)
            dfs(tree, level + 1, pos * 2, curSum);
    }
}