class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        Set<Integer> set = new HashSet<>();
        for (int[] mine : mines)
            set.add(mine[0] * N + mine[1]);
        
        int[][] left = new int[N][N];
        int[][] right = new int[N][N];
        int[][] top = new int[N][N];
        int[][] down = new int[N][N];

        for (int i = 0; i < N; i++) {
            int oleft = 0, oright = 0;
            for (int j = 0; j < N; j++) {
                // Left
                left[i][j] = oleft;
                if (!set.contains(i * N + j))    oleft++;
                else    oleft = 0;
                
                // Right
                int rj = N - j - 1;
                right[i][rj] = oright;
                if (!set.contains(i * N + rj))    oright++;
                else    oright = 0;
            }
        }
        
        for (int j = 0; j < N; j++) {
            int otop = 0, odown = 0;
            for (int i = 0; i < N; i++) {
                // Top
                top[i][j] = otop;
                if (!set.contains(i * N + j))    otop++;
                else    otop = 0;
                
                // Down
                int ri = N - i - 1;
                down[ri][j] = odown;
                if (!set.contains(ri * N + j))    odown++;
                else    odown = 0;
            }
        }
        
        int MAX = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (set.contains(i * N + j))    continue;
                MAX = Math.max(MAX, Math.min(Math.min(top[i][j], left[i][j]), Math.min(down[i][j], right[i][j])) + 1);
            }
        }
        
        return MAX;
    }
}