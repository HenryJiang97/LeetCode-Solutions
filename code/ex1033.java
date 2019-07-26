class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] pos = {a, b, c};
        Arrays.sort(pos);
        int min_gap = Integer.MAX_VALUE, total_gap = 0;
        
        for (int i = 1; i < 3; i++) {
            min_gap = Math.min(min_gap, pos[i] - pos[i - 1] - 1);
            total_gap += (pos[i] - pos[i - 1] - 1);
        }
        
        int min = total_gap == 0 ? 0 : min_gap == 1 || min_gap == 0 ? 1 : 2;
        return new int[]{min, total_gap};
    }
}