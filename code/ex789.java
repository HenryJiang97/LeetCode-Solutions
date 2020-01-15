class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int source2target = Math.abs(target[0]) + Math.abs(target[1]);
        for (int[] ghost : ghosts) {
            int ghost2target = Math.abs(target[0] - ghost[0]) + Math.abs(target[1] - ghost[1]);
            if (ghost2target <= source2target)    return false;
        }
        return true;
    }
}