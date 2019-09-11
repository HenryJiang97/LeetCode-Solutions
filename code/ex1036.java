// Since the max amount of blocked squares are only 200, which means that if either source or target are surrounded by blocks, the larest surrounding is at most 200 * 200, if one block square is beyond this range, then return true, in other word, check if one vacant square appears among the range of 200*200 space.

class Solution {
    private int max = (int)1e6;
    private int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    private boolean dfs(Set<Integer> blocked, int[] source, int[] target, int i, int j, Set<Integer> visited) {
        // If current square is out of the range, return true
        if (Math.abs(i - source[0]) > 200 || Math.abs(j - source[1]) > 200 || (visited.size() > 0 && i == target[0] && j == target[1]))
            return true;
        
        visited.add(i * max + j);
        
        // Go four directions
        boolean ret = false;
        for (int[] dir : directions) {
            int next_i = i + dir[0], next_j = j + dir[1];
            
            if (next_i < 0 || next_j < 0 || next_i >= max || next_j >= max 
                || blocked.contains(next_i * max + next_j) || visited.contains(next_i * max + next_j))
                continue;
            
            ret |= dfs(blocked, source, target, next_i, next_j, visited);
            if (ret)    return true;
        }
        
        return false;
    }
    
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        int n = blocked.length;
        
        // Save blocked squares to a set for later use
        Set<Integer> blockedSet = new HashSet<>();
        for (int i = 0; i < n; i++)    blockedSet.add(blocked[i][0] * max + blocked[i][1]);
        
        // DFS check for a vacant square within the range of 200*200
        return dfs(blockedSet, source, target, source[0], source[1], new HashSet<Integer>())
            && dfs(blockedSet, target, source, target[0], target[1], new HashSet<Integer>());
    }
}