import java.util.*;

class Solution {
    private class pair {
        int i;
        int j;
        int dis;
        pair (int i, int j, int dis) {
            this.i = i;
            this.j = j;
            this.dis = dis;
        }
    }
    
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] res = new int[R * C][2];
        
        PriorityQueue<pair> pq = new PriorityQueue<>(new Comparator<pair>() {
            @Override
            public int compare(pair a, pair b) {
                return a.dis - b.dis;
            }
        });
        
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                pq.offer(new pair(i, j, (int)Math.abs(r0 - i) + (int)Math.abs(c0 - j)));
            }
        }
        
        int i = 0;
        while (!pq.isEmpty()) {
            pair p = pq.poll();
            res[i][0] = p.i;
            res[i++][1] = p.j;
        }
        
        return res;
    }
}